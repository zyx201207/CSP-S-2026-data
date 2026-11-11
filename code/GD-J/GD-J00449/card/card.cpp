#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a[500005];
int ans[300005],last[300005],cnt[300005];
bool flag[300005];
struct s{
	int l,r,sum,lazy;
	bool flag;
}tree[2000006];
int lson(int p){return p*2;}
int rson(int p){return p*2+1;}
void build(int l,int r,int p){
	tree[p].l=l;
	tree[p].r=r;
	tree[p].flag=false;
	tree[p].sum=0;
	if(l==r)return;
	else{
		int mid=(l+r)/2;
		build(l,mid,lson(p));
		build(mid+1,r,rson(p));
	}
}
void lazy(int l,int r,int p,int k,bool f){
//	if(f)cout<<tree[p].l<<' '<<tree[p].r<<endl;
	if(tree[p].l==l&&tree[p].r==r){
		if(f)tree[p].flag=true;
		if(!tree[p].flag)tree[p].sum+=k;
		if(!tree[p].flag)tree[p].lazy+=k;
	}else{
		if(!tree[lson(p)].flag)tree[lson(p)].sum+=tree[p].lazy;
		if(!tree[rson(p)].flag)tree[rson(p)].sum+=tree[p].lazy;
		if(!tree[lson(p)].flag)tree[lson(p)].lazy+=tree[p].lazy;
		if(!tree[rson(p)].flag)tree[rson(p)].lazy+=tree[p].lazy;
		tree[lson(p)].flag|=tree[p].flag;
		tree[rson(p)].flag|=tree[p].flag;
		tree[p].lazy=0;
		int mid=(tree[p].l+tree[p].r)/2;
		if(l<=mid&&r<=mid)lazy(l,r,lson(p),k,f);
		if(l<=mid&&r>mid){
			lazy(l,mid,lson(p),k,f);
			lazy(mid+1,r,rson(p),k,f);
		}
		if(l>mid&&r>mid)lazy(l,r,rson(p),k,f);
	}
}
int query(int x,int p){
	if(tree[p].l==x&&tree[p].r==x){
		return tree[p].sum;
	}else{
		if(!tree[lson(p)].flag)tree[lson(p)].sum+=tree[p].lazy;
		if(!tree[rson(p)].flag)tree[rson(p)].sum+=tree[p].lazy;
		if(!tree[lson(p)].flag)tree[lson(p)].lazy+=tree[p].lazy;
		if(!tree[rson(p)].flag)tree[rson(p)].lazy+=tree[p].lazy;
		tree[lson(p)].flag|=tree[p].flag;
		tree[rson(p)].flag|=tree[p].flag;
		tree[p].lazy=0;
		int mid=(tree[p].l+tree[p].r)/2;
		if(x<=mid)return query(x,lson(p));
		if(x>mid)return query(x,rson(p));
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	/*if(n<=500){
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++){
				cnt[j]=0;
				last[j]=0;
				flag[j]=true;
			}
			for(int j=i;j<=n;j++){
				cnt[a[j]]++;
				if(i==6)cout<<j<<' '<<cnt[a[j]]<<endl;
				if(last[a[j]]&&flag[last[a[j]]]){
					for(int k=last[a[j]];k<j;k++){
						cnt[a[k]]--;
						flag[a[k]]=false;
					}
					cout<<last[a[j]]<<'a'<<j<<endl;
				}if(i==6)cout<<j<<' '<<cnt[a[j]]<<endl;
				last[a[j]]=j;
			}
			for(int j=1;j<=m;j++){
				if(cnt[j])ans[j]++;
				cout<<cnt[j]<<' ';
			}
			cout<<endl;
		}
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
		return 0;
	}*/
	build(1,n,1);
	for(int i=n;i>=1;i--){
		if(last[a[i]]&&query(last[a[i]],1)+n-last[a[i]]==n-i){
			lazy(i+1,last[a[i]],1,0,true);
		}
		lazy(i,n,1,1,false);
		last[a[i]]=i;
	}
	for(int i=1;i<=m;i++)last[i]=0;
	for(int i=n;i>=1;i--){
		int sum=query(i,1);
		int L=n-i,R=L+sum;
		if(R>last[a[i]])ans[a[i]]=ans[a[i]]+R-max(last[a[i]],L);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3

*/
