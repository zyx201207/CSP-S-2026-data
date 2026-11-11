#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int n,m;
int best;
void dfs(int b[],int d,int vis[]){
	if(d==m){
		int ans=(1<<30)-1;
		for(int i=1;i<=m;i++)ans&=b[i];
		if(ans>best)best=ans;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[d+1]=a[i];
			dfs(b,d+1,vis);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(m==1){
		printf("%d\n",a[n]);
	}else if(m==n){
		int ans=(1<<30)-1;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		printf("%d",ans);
	}else if(m==2||n<=20){
		int b[2005]={0},vis[2005]={0};
		dfs(b,0,vis);
		printf("%d",best);
	}else{
		int ans=(1<<30)-1;
		int k=0,i=n;
		while(k<m){
			while((ans&a[i])==0)i--;
			ans&=a[i];
			i--;
			k++;
		}
		printf("%d",ans);
	}
}
