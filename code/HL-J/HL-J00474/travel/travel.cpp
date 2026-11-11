#include<bits/stdc++.h>
using namespace std;
long long s,c;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a,b;
	char c[1005],d[1005];
	cin>>a;
	for(int i=1;i<=3;i++)
	{
		cin>>c[i];
	}
	cin>>b;
	for(int i=1;i<=3;i++)
	{
		cin>>d[i];
	}
	if(a==b) cout<<1;
	else cout<<0;
	if(a==b and c[2]==d[2])
	cout<<1;
	else cout<<0;
		if(a==b and c[2]==d[2] and((c[3]=='A' and (d[3]=='B' or d[3]=='C'))or(c[3]=='B' and(d[3]=='A' or d[3]=='C'))or(c[3]=='C' and (d[3]=='A' or d[3]=='B'))or(c[3]=='D'and d[3]=='F')or(c[3]=='F'and d[3]=='D')))
	cout<<1;
	else cout<<0;
	if(a==b and c[2]==d[2] and((c[3]=='A' and d[3]=='B')or(c[3]=='B' and(d[3]=='A' or d[3]=='C'))or(c[3]=='C' and d[3]=='A')or(c[3]=='D'and d[3]=='F')or(c[3]=='F'and d[3]=='D')))
	cout<<1;
	else cout<<0;
	return 0;
}
