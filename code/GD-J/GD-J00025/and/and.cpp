#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,maxa=1<<30;
int N,M,line=-1,su[35];
struct choice{
	int w,fi,se;
}a[maxn];
bool f[maxn][35],maxx[35];
void Build(int p){
	int q=a[p].w;
	a[p].fi=p-1,a[p].se=p+1;
	f[p][0]=q%2,su[0]+=f[p][0];
	for(int i=1;i<=30;i++)
		q=q>>1,f[p][i]=q%2,su[i]+=f[p][i];
}
inline void con(int p){
	a[a[p].fi].se=a[p].se;
	a[a[p].se].fi=a[p].fi;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(f,0,sizeof(f));
	memset(maxx,0,sizeof(maxx));
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i].w),Build(i);
	a[N].se=-1,a[0].se=1;
	for(int i=30;i>=0;i--)
		if (su[i]>=M){
			line=i;
			break;
		}
	if (line==-1){
		printf("0");
		return 0;
	}
	maxx[line]=1;
	for(int i=1;i<=N;i++)
		if (!f[i][line])
			con(i);
	int K=line-1,sum;
	while(K>=0){
		sum=0;
		for(int i=0;i<=N&&i!=-1;i=a[i].se)
			if (f[i][K])
				sum++;
		if (sum<M){
			K--;
			continue;
		}
		for(int i=0;i<=N&&i!=-1;i=a[i].se)
			if (!f[i][K]&&i!=0)
				con(i);
		maxx[K]=1,K--;
		//O(4*10^5)
	}//O(8*10^6)
	//O(1.4*10^7)
	//ÊÕÎ²¼ÆËã
	long long last=0;
	for(int i=30;i>=0;i--)
		last+=maxx[i]<<i;
	printf("%lld",last);
	return 0;
}
