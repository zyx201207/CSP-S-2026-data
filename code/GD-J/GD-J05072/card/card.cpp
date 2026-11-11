#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=3e5+7;
int ans[M];
int a[N],tr[N];
int lst[M],nxt[N];
int n,m;
int lb(int x){
	return x&(-x);
}
void upd(int x,int d){
	for(int i=x;i<=n;i+=lb(i))tr[i]+=d;
}
int qry(int x){
	int s=0;
	for(int i=x;i;i-=lb(i))s+=tr[i];
	return s;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(lst[a[i]])nxt[lst[a[i]]]=i;
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int x=qry(i);
		ans[a[i]]=max(ans[a[i]],i-x);
		if(nxt[i]){
			int d=i-x;
			upd(i+1,d);
			upd(nxt[i],-d);
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
