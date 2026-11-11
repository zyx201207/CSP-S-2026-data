#include<bits/stdc++.h>
using namespace std;
int n,m,d,a[500005],ans[300005];
string s;
char t;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout<<s.substr(0,2);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		s="";
		for(int j=i;j<=n;j++)
		{
			d=s.find(to_string(a[j]));
			if(d==-1) s+=to_string(a[j]);
			else s=s.substr(0,d+1);
		}
		t=i-'0';
		for(int j=0;j<s.size();j++) ans[s[j]-'0']++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
