#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FN "hub"
int c,T,n,k,u,v,rt,l,r,mid,ct,id,cnt,h[1000005],rd[1000005],ln[1000005],f[1000005];
int r1[1000005],r2[1000005];
int ql,qr,qd[1000005];
struct lyt{
	int prv,to;
}p[2000005];
void add(int u,int v){
	p[++cnt].prv=h[u];
	p[cnt].to=v;
	h[u]=cnt;
}
void dfs(int x,int xt,int fa){
	f[x]=fa;
	for(int i=h[x];i!=0;i=p[i].prv){
		if(p[i].to==fa)continue;
		if(ln[p[i].to]<=xt)continue;
		dfs(p[i].to,xt,x);
	}
}
bool check(int x){
//	cout<<x<<"!"<<endl;
	ct=0;
	for(int i=1;i<=n;i++){
		if(ln[i]>x)ct++;
	}
	if(ct<=k)return true;
//	cout<<x<<"?"<<endl;
	rt=0;
	for(int i=1;i<=n;i++){
		if(ln[i]>x){
			r2[i]=0;
			for(int j=h[i];j!=0;j=p[j].prv){
				if(ln[p[j].to]>x){
					r2[i]++;
				}
			}
			if(r2[i]!=r1[i])rt=i;
		}
	}
//	cout<<x<<"?"<<endl;
	dfs(rt,x,0);
//	cout<<x<<"?"<<endl;
	for(int i=1;i<=n;i++){
		if(ln[i]>x&&r2[i]!=r1[i]&&i!=rt){
			u=f[i];v=0;
			while(r2[u]==r1[u]){
				v++;
				u=f[u];
			}
			if(ct-min(v,2*x-1)<=k)return true;
		}
	}
//	cout<<x<<"?"<<endl;
	return false;
}
int main(){
	freopen(FN".in","r",stdin);
	freopen(FN".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		if(c>=13&&c<=14){
			if(k==n)cout<<0;
			else if(k>=n/2)cout<<1;
			else cout<<(n/2-k-1)/4+2;
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			rd[i]=0;r1[i]=r2[i]=0;h[i]=0;ln[i]=0;
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			add(u,v);add(v,u);
			rd[u]++;rd[v]++;
			r1[u]++;r1[v]++;
		}
		ql=1;qr=0;
		for(int i=1;i<=n;i++){
			if(rd[i]==1)qd[++qr]=i,ln[i]=1;
		}
		while(ql<=qr){
			id=qd[ql++];
			for(int i=h[id];i!=0;i=p[i].prv){
				if(rd[p[i].to]>1){
					ln[p[i].to]=max(ln[p[i].to],ln[id]+1);
					if(--rd[p[i].to]==1){
						qd[++qr]=p[i].to;
					}
				}
			}
		}
		l=0;r=n;
		while(l<r){
			mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}
/*
lose!!!!!
I dont know how to do it

and i only get10 pts
*/
