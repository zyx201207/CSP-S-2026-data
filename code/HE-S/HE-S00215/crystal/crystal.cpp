#include<bits/stdc++.h>
using namespace std;
int n,num,max_num=-1;
long long m,m2,c[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);//cin>>n>>m;
	m2=m;
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);//cin>>c[i];
	sort(c+1,c+n+1);
	for(int i=n;i>=1;i--)
	{
		if(c[i]==c[i+1])
		{
			//cout<<i<<" i skip\n";
			continue;
		}
		num=0;
		m=m2;
		for(int j=i-1;j>=1;j--)
		{
			if(m>=c[i]-c[j])
			{
				m-=c[i]-c[j];
				num++;
				//cout<<num<<" num plus one\n";
			}
			else break;
		}
		max_num=max(max_num,num);
		//cout<<num<<' '<<max_num<<' '<<i<<'\n';
	}
	printf("%d",max_num+1);//cout<<max_num+1;
}
