#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+5;
int n;
int len[mx];
char c[mx];
string s;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>len[i]>>c[i];
		while(len[i]--)s+=c[i];
	}
	for(int l=0,r=(int)s.size()-1;l<r;l++,r--)
	{
		if(s[l]!=s[r])ans++;
	}
	cout<<ans;
	return 0;
}
/*

n<=2e5
a[i]<=1e9
3
2 a
2 6
1 c



*/

