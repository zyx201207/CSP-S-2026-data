#include<bits/stdc++.h>
using namespace std;
long long a,n,len,ans;
char c;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	len=s.length()-1;
	for(long long i=0;i<=len/2-1;i++){
		if(s[i]!=s[len-i]){
			ans++;
		}
	}
	cout<<ans;

	return 0;
}
