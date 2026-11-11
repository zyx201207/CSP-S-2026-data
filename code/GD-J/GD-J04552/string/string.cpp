#include<bits/stdc++.h>
using namespace std;
string s;
int n,x;
long long ans;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c;
		for(int i=1;i<=x;i++)
		{
			s+=c;	
		}	
	}
	int len=s.size();
	for(int i=0;i<=len/2;i++)
	{
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
 } 
