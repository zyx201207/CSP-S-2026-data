#include<bits/stdc++.h>
using namespace std;
//注意区分调试语句和运行语句

//awa 
int c,t,n;
long long d;
long long x[2000005]; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//务必提交前取消freopen的注释
//	scanf("%d%d",&c,&t);
	cin>>c>>t;
	while(t--)
	{
		long long ans=0;
//		scanf("%d%lld",&n,&d);
		cin>>n>>d;
		bool f=true;
		long long w=0;
//		scanf("%lld",&x[1]);
		cin>>x[1];
		for(int i=2;i<=n;i++)
		{
//			scanf("%lld",&x[i]);
			cin>>x[i];
			if(w!=x[i]-x[i-1]&&w!=0)
			{
				f=false;
			}
			w=x[i]-x[i-1];
		}
		if(f)
		{
			long long s=d/w;
			s=s*2-(long long)1;
			ans=max((long long)0,(long long)n-s);
			if(s==1||s==-1)
			{
				ans=0;
			}
		}
//		printf("%lld\n",ans);
		cout<<ans<<"\n";
	}
	return 0;
}

