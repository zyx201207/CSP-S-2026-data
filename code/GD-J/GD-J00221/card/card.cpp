#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[500005],l[300005],h[500005],k[300005],rt[500005],cnt,c[300005],u,y,x;
bool p[300005];
deque<int> q;
struct tree{
	int l,r,v;
}s[10000100];
void upd(int &x,int y,int l,int r,int q){
	cnt++;
	x=cnt;
	s[x]=s[y];
	s[x].v++;
	if(l==r)return ;
	int m=(l+r)>>1;
	if(q<=m)upd(s[x].l,s[y].l,l,m,q);
	else upd(s[x].r,s[y].r,m+1,r,q);
	return ;
}
int sum(int x,int y,int l,int r,int q,int w){
	if(r<q||l>w)return 0;
	if(l>=q&&r<=w)return s[y].v-s[x].v;
	int m=(l+r)>>1;
	return sum(s[x].l,s[y].l,l,m,q,w)+sum(s[x].r,s[y].r,m+1,r,q,w);
}
int ans(int x,int y,int l,int r,int k){
	if(l==r)return l;
	int m=(l+r)>>1;
	if(s[s[y].l].v-s[s[x].l].v>=k)return ans(s[x].l,s[y].l,l,m,k);
	else return ans(s[x].r,s[y].r,m+1,r,k-s[s[y].l].v+s[s[x].l].v);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=5000){
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(!p[a[j]]){
					q.push_back(a[j]);
					p[a[j]]=1;
				}
				else{
					while(q.back()!=a[j]){
						p[q.back()]=0;
						q.pop_back();
					}
				}
			}
			while(!q.empty()){
				k[q.back()]++;
				p[q.back()]=0;
				q.pop_back();
			}
		}
		for(int i=1;i<=m;i++)printf("%d ",k[i]);
		return 0;
	}
	for(int i=1;i<=m;i++)c[i]=n+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		h[i]=l[a[i]];
		l[a[i]]=i;
		upd(rt[i],rt[i-1],0,n,h[i]);
	}
	for(int i=n;i>=1;i--){
		u=sum(rt[i],rt[n],0,n,0,i-1);
		y=ans(rt[i],rt[n],0,n,u);
		if(y<c[a[i]]){
			k[a[i]]=k[a[i]]+min(i,c[a[i]])-y;
			c[a[i]]=y;
		}
		u=sum(rt[i],rt[n],0,n,0,h[i]);
		x=ans(rt[i],rt[n],0,n,u+1);
		u=sum(rt[y],rt[i],0,n,0,x-1);
		x=ans(rt[y],rt[i],0,n,u);
		if(x>h[i]){
			k[a[i]]=k[a[i]]+max(0,min(c[a[i]],x)-h[i]);
			c[a[i]]=min(c[a[i]],h[i]);
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",k[i]);
	return 0;
}
