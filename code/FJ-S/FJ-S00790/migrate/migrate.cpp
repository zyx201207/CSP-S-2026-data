#include<bits/stdc++.h>
using namespace std;
#define N 2000010
#define M 100010
int c,t,n,m[N];
long long x[N],d,ans=0;
int cnt[100010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int w=1;w<=t;w++)
	{
		scanf("%d%d",&n,&d);
		memset(m,0,sizeof(m));
		memset(x,0,sizeof(x));
		ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&x[i]);
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-2]<=d){
				m[i-2]-=1;
				int b=1;
				while(x[i+b]-x[i-2]<=d&&i+b<=n)b++;
				m[i+b-1]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			m[i]+=m[i-1];
		}
		for(int i=1;i<=n;i++)
		{
			if(m[i]!=m[i-1])
			{
				if(cnt[m[i-1]]==-2)ans+=cnt[m[i-1]];
				cnt[m[i]]=0;
			}
			cnt[m[i]]++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

