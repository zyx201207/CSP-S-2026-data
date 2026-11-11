#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+500;
int a[N],ans[N],nxt[N],en[N];
void solve1(){
	for(int i=n;i>=1;i--){
		if(en[a[i]]==-1){
			en[a[i]]=i;
		}
		nxt[i]=en[a[i]];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			j=nxt[j];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans[i]=0,nxt[i]=-1,en[i]=-1;
	}
	int time=2e9;
	if(n<=time){
		solve1();
		return 0;
	}
	a[n+1]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			ans[a[i]]+=i;
		}
		
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
} 
