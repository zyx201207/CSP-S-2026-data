#include<bits/stdc++.h> 
using namespace std;
string s;
int a,ans,n;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		scanf("%d",&a);
		cin>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	int r=(s.size()-1)/2; 
	for(int i=0;i<=r;i++)
	{
		if(s[i]!=s[s.size()-i-1]) 
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
