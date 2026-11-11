#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,d,c,t,a[2000010],p[2000010],tmp1,tmp2,res;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(scanf("%lld%lld",&c,&t);t--;)
	{
		res=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int l=1,r=1;l<=n+2;l++)
		{
			while(r+1<=n&&a[r+1]-a[l]<=d)
				r++;
			p[l]=r-l;
		}
//		for(int i=1;i<=n;i++)
//			cout<<p[i]<<" ";
//		cout<<"\n";
		tmp1=tmp2=0;
		for(int i=1;i<=n;i++)
		{
			tmp2++;
			if(p[i]==2&&p[i+1]==2)
			{
//				cout<<"i="<<i<<" "<<"tmp1="<<tmp1<<" tmp2="<<tmp2+1<<"\n";
				res+=tmp1*(tmp2+1);
				tmp1=tmp2;
				tmp2=0;
				i+=2;
			}
			else if(p[i]==2&&p[i+1]==1)
			{
//				cout<<"i="<<i<<" "<<"tmp1="<<tmp1<<" tmp2="<<tmp2+1<<"\n";
				res+=tmp1*(tmp2+1);
				tmp1=tmp2=0;
			}
			else if(p[i]>2)
			{
//				cout<<"i="<<i<<" "<<"tmp1="<<tmp1<<" tmp2="<<tmp2+1<<"\n";
				res+=tmp1*(tmp2+1);
				tmp1=tmp2=0;
			}
			else if(p[i]==0)
			{
//				cout<<"i="<<i<<" "<<"tmp1="<<tmp1<<" tmp2="<<tmp2+1<<"\n";
				res+=tmp1*tmp2;
				tmp1=tmp2=0;
			}
		}
		res+=tmp1*(tmp2+1);
		printf("%lld\n",res);
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
*/
