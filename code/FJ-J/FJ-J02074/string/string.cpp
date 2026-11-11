#include<bits/stdc++.h>
using namespace std;
int n,a[200050];
long long ans=0,sum=0;
string s,b,c[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
			b+=c[i];
		}
	}	
	reverse(s.begin(),s.end());
	if(s==b) cout<<0;
	else
	{
		for(int i=0;i<=sum-1;i++)
		{
			string p=s.substr(i,1);
			string q=b.substr(i,1);
			if(p==q) continue;
			else ans++;
		}
		cout<<ans/2;
	}
	return 0;
}
