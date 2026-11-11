#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+2;
int op,_,n,b[N],mn,cnt;
ll m,a[N],ans;
void dfs(int x,int t,int id){
	if(cnt>2) return ;
	if(x==t){
		if(mn==id) ++cnt;
		else if(mn==INT_MAX) mn=id,++cnt;
		return ;
	}
	for(int i=b[x];i>x;--i) dfs(i,t,id+1);
}
int main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	scanf("%d %d\n",&op,&_);
	while(_--){
		scanf("%d %lld\n",&n,&m);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		if(n<4 || a[n]-a[1]<=m){
			puts("0\n");
			continue;
		}
		int p=1;
		for(int i=1;i<=n;++i){
			while(a[p]-a[i]<m && p<n) ++p;
			if(a[p]-a[i]>m) --p;
			b[i]=p;
		}
		for(int i=1;i<n;++i)
			for(int j=i+3;j<=n;++j){
				cnt=0,mn=INT_MAX,dfs(i,j,0);
				if(cnt==2) ++ans;
			}
		printf("%lld\n",ans),ans=0;
	}
	fclose(stdin),fclose(stdout);
	return 0;
}
