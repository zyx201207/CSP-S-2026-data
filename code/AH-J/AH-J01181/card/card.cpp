#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],lst[300005];
struct node{
	int s,t;
}tree[2000005];
void pushup(int id){
	tree[id].s=tree[id*2].s+tree[id*2+1].s;
	return; 
}
void f(int k,int l,int r,int id){
	tree[id].t+=k;
	tree[id].s+=k*(r-l+1);
	return;
}
void pushdown(int id,int l,int r){
	int mid=(l+r)/2;
	f(tree[id].t,l,mid,id*2);
	f(tree[id].t,mid+1,r,id*2+1);
	tree[id].t=0;
	return;
}
void update(int x,int y,int l,int r,int id,int k){
	if(l>=x&&r<=y){
		tree[id].s+=(r-l+1)*k;
		tree[id].t+=k;
		return;
	}
	int mid=(l+r)/2;
	pushdown(id,l,r);
	if(x<=mid)update(x,y,l,mid,id*2,k);
	if(y>mid)update(x,y,mid+1,r,id*2+1,k);
	pushup(id);
	return;
}
int find(int x,int y,int l,int r,int id){
	if(l>=x&&r<=y)return tree[id].s;
	int mid=(l+r)/2,sum=0;
	pushdown(id,l,r);
	if(x<=mid)sum+=find(x,y,l,mid,id*2);
	if(y>mid)sum+=find(x,y,mid+1,r,id*2+1);
	pushup(id);
	return sum;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)lst[a[i]]=i;
	for(int i=1;i<=n;i++){
		if(lst[a[i]]==i)continue;
		if(i+1<=lst[a[i]]-1)update(i+1,lst[a[i]]-1,1,n,1,1);
	}
	for(int i=1;i<=n;i++){
		if(i==lst[a[i]]){
			ans[a[i]]=i-find(i,i,1,n,1);
			int j=i+1;
			if(j+1<=lst[a[j]]-1&&lst[a[j]]-1<=n)update(j+1,lst[a[j]]-1,1,n,1,ans[a[i]]);
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
