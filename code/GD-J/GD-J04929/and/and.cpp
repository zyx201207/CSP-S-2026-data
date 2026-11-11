#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],pre[200010];
long long ma=0;
map<long long,bool> p;
void dfs(int i,int pick,long long sum){
//	printf("%d %d %lld\n",i,pick,sum);
	if(pick==m){
		ma=max(ma,sum);
		return;
	}
	if(i==n+1) return;
	if(pick==0){
		dfs(i+1,pick+1,a[i]);
		dfs(i+1,pick,sum);
	}
	if(pick>=1){
		dfs(i+1,pick+1,(sum&a[i]));
		dfs(i+1,pick,sum);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	int k=1;
	long long num=1;
	while(k<=31){
		num=num*2;
		p[num-1]=true;
		k++;
	}
	bool flat=true;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(p[a[i]]!=true) flat=false;
	}
	if(m==1){
		for(int i=1;i<=a[i];i++)
			ma=max(ma,a[i]);
		printf("%lld",ma);
		return 0;
	}
	if(n==m){
		ma=a[1];
		for(int i=1;i<=n;i++) ma=(ma&a[i]);
		printf("%lld",ma);
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j) ma=max(ma,(a[i]&a[j]));
		printf("%lld",ma);
		return 0;
	}
	if(flat){
		sort(a+1,a+n+1,greater<long long>());
		printf("%lld",a[m]);
		return 0;
	}
	dfs(1,0,0LL);
	printf("%lld",ma);
	return 0;
}
