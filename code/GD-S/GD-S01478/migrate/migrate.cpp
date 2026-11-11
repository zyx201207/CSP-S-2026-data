#include<bits/stdc++.h>
#define ls(p) p<<1
#define rs(p) p<<1|1
using namespace std;
bool mst;
int n;
int tr[8000006];
bool tg[8000006];
long long w[2000006];
bool med;
void up(int root){
	tr[root]=tr[ls(root)]+tr[rs(root)];
}
void down(int root,int l,int r){
	if(tg[root]){
		int mid=l+r>>1;
		tr[ls(root)]+=mid-l+1;
		tr[rs(root)]+=r-mid;
		tg[ls(root)]=1;
		tg[rs(root)]=1;
		tg[root]=0;
	}
}
void build(int root,int l,int r){
	tr[root]=tg[root]=0;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(ls(root),l,mid);
	build(rs(root),mid+1,r); 
}
void change(int root,int l,int r,int x,int y){
	if(l==r){
		tr[root]=y;
		return;
	}
	down(root,l,r);
	int mid=l+r>>1;
	if(x<=mid)change(ls(root),l,mid,x,y);
	else change(rs(root),mid+1,r,x,y);
	up(root);
}
void rg_change(int root,int l,int r,int x,int y){
	if(x<=l && r<=y){
		tr[root]=r-l+1;
		tg[root]=1;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid)rg_change(ls(root),l,mid,x,y);
	if(y>mid)rg_change(rs(root),mid+1,r,x,y);
	up(root);
}
int query(int root,int l,int r,int x,int y){
	if(x<=l && r<=y)return tr[root];
	down(root,l,r);
	int ans=0,mid=l+r>>1;
	if(x<=mid)ans+=query(ls(root),l,mid,x,y);
	if(y>mid)ans+=query(rs(root),mid+1,r,x,y);
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long d;
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++)cin>>w[i];
		if(c<=10){
			for(int i=2;i<=n;i++){
				long long ld=w[i]-d,rd=w[i]-1;
				build(1,1,n);
				int l=lower_bound(w+1,w+n+1,ld)-w,r=upper_bound(w+1,w+n+1,rd)-w-1;
				if(l>r)continue;
				rg_change(1,1,n,l,r);
				int dis=2;
				for(int j=l-1;j>=1;j--){
					ld=w[j]+1,rd=w[j]+d;
					int nl=lower_bound(w+1,w+n+1,ld)-w,nr=upper_bound(w+1,w+n+1,rd)-w-1;
					if(nl>nr)break;
					if(nr<l){
						dis++;
						l=j+1;
					}
					else nl=max(nl,l);
					int x=query(1,1,n,nl,nr);
					if(x==2)ans++;
					change(1,1,n,j,x);
				}
			}
			build(1,1,n);
			cout<<ans<<"\n";
		}
		else if(c<=12){
			long long dis=w[2]-w[1];
			d/=dis;
			if(d<=1){
				cout<<0<<"\n";
				continue;
			}
			cout<<max(0LL,n-(2*d-1))<<"\n";
		}
		else cout<<"0\n";
	}
	return 0;
}
//记得提醒我去学whk，期中马上就来了 
