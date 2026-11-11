#include<bits/stdc++.h>
using namespace std;
inline bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	long long m,s;cin>>m>>m;
	vector<long long>v;
	while(cin>>s)v.push_back(s);
	sort(v.begin(),v.end(),cmp);
	int cnt=v[0];
	for(int i=1;i<m;i++)cnt&=v[i];
	cout<<cnt;
	return 0;
}
