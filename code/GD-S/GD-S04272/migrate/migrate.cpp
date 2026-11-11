#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
struct Z{
	long long l,num;
};
long long c,t;
vector<long long> x(5005,0);
vector<vector<Z>> q(5005,vector<Z>(5010,{0x3f3f3f3f,0}));
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		long long n,d,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) q[i][j]={0x3f3f3f3f,0};
		for(int i=1;i<=n;i++) cin>>x[i];
		for(long long i=1;i<n;i++) q[i][i+1].num=1,q[i][i+1].l=1;
		for(long long l=2;l<n;l++) for(long long i=1;i+l<=n;i++)
		{
			if(x[i+l]-x[i]<=d)
			{
				q[i][l+i].num=1,q[i][l+i].l=1;
				continue;
			}
			for(long long j=l+i;j>=i+1;j--)
			{
				if(q[i][j].l+q[j][i+l].l<q[i][i+l].l) q[i][i+l].l=q[i][j].l+q[j][i+l].l,q[i][i+l].num=q[i][j].num*q[j][i+l].num;
				else if(q[i][j].l+q[j][i+l].l==q[i][i+l].l) q[i][i+l].num+=q[i][j].num*q[j][i+l].num;
			}
		}
		for(long long i=1;i<n;i++) for(long long j=i+1;j<=n;j++) if(q[i][j].num==2) cnt++;
		//for(long long i=1;i<n;i++) for(long long j=i+1;j<=n;j++) cout<<q[i][j].l<<" "<<q[i][j].num<<"\n";
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
5 3
-2 -1 0 1 2

0 1
5 3
-3 0 2 3 4
*/
