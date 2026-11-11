#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],h=0,sum[500010],pre[300010];
struct nd{
	int p;
	bool f;
}vis[300010];
struct st{
	int p,s;
}stk[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=n;i>=1;i--){
		if(vis[a[i]].f!=1){
			stk[++h].s=a[i];
			stk[h].p=i;
			vis[a[i]].f=1;
			vis[a[i]].p=h;
			sum[stk[1].p]++;
			sum[stk[h].p-1]--;
		}
		else{
			h=vis[a[i]].p;
			sum[stk[1].p]++;
			sum[stk[h].p-1]--;
			stk[h].p=i;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<" ";
//	}
//	for(int i=1;i<=h;i++){
//		cout<<stk[i].p<<" ";
//	}
	for(int i=n;i>=stk[h].p;i--){
		sum[i]+=sum[i+1];
		pre[a[i]]+=sum[i];
//		cout<<a[i]<<" "<<sum[i]<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<pre[i]<<' ';
	}
	return 0;
}

