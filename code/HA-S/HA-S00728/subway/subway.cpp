#include<bits/stdc++.h>
using namespace std;
long long w[5009],s[509];
long long x[509][5009],y[509][5009];
long long t[1009][1009];
long long c1,n,m,d,q;
long long f(long long a,long long b)
{
	if(t[a][b]!=0)
	{
		long long w=t[a][b],t1=x[w][a],t2=x[w][b];
		return y[w][t1]+y[w][t2];
	}
	long long o=a;
	long long sum=99999;
	for(long long i=a+1;i<=m;i++)
	{
		if(t[a][i]&&f(i,b)<sum) 
		{
			sum=f(i,b);
			o=i;
		}
	}
	long long c=t[a][o];
	return sum+y[c][a]+y[c][o];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c1>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>s[i];
		for(long long j=1;j<=s[i];j++)
		{
			cin>>x[i][j]>>y[i][j];
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=s[i];j++)
		{
			for(long long l=j+1;l<=s[i];l++)
			{
				long long q1=x[i][j],q2=x[i][l];
				t[q1][q2]=t[q2][q1]=i;
			}
		}
	}
	for(long long i=1;i<=q;i++)
	{
		long long x1,y1;
		cin>>x1>>y1;
		long long t=0;
		cout<<f(x1,y1)+w[x1]+w[y1]<<endl;
	}
	return 0;
}
