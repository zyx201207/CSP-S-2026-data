#include<bits/stdc++.h>
#define siz(_) ((int)_.size())
#define pb emplace_back
#define mk make_pair
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=2e6+5,K=6;
int n,nxt[N];
ll ans=0,f[N][K];
/*
w : d[w]!=d[w+1]

op1 : d[w-1]==d[w]
op2 : d[w-2]==d[w]
op3 : f[w]==2
op4 : f[w-1]==1
*/
inline int get_id(bool op1,bool op2,bool op3,bool op4){
	if(op3==0){
		if(op1==0) return 0;
		else{
			if(op4==0) return 1;
			else{
				if(op2==0) return 2;
				else return 3;
			}
		}
	}else{
		if(op1==1) return 4;
		return 5;
	}
}
inline void get(int i,int j){
	f[i][j]=0;
	ll &res=f[i][j];
	if(j==0){
		int l=i;
		if(l==nxt[i]);
		res+=f[nxt[i]][get_id(nxt[i]>i+1,nxt[i]>i+2,0,1)];
	}else if(j==1){
		int l=max(i,nxt[i-1]);
		if(l==nxt[i]) return;
		res+=f[nxt[i]][get_id(nxt[i]>i+1,nxt[i]>i+2,0,l!=nxt[i]-1)];
	}else if(j==2){
		int l=max(i,nxt[i-1]);
		res+=l-i;
		if(l==i){
			if(i==nxt[i]) return;
			res+=f[nxt[i]][get_id(nxt[i]>i+1,nxt[i]>i+2,0,l!=nxt[i]-1)];
		}else{
			if(l==nxt[i]){
				res+=f[nxt[i]][get_id(nxt[i]>i+1,nxt[i]>i+2,1,0)];
			}else{
				res+=f[nxt[i]][get_id(nxt[i]>i+1,nxt[i]>i+2,0,l!=nxt[i]-1)];
			}
		}
	}else if(j==3){
		int st=max(nxt[i-2],i);
		int l=max(i,nxt[i-1]);
		res+=l-st;
		if(l==st){
			if(st==nxt[i]) return;
			res+=f[nxt[i]][get_id(nxt[i]>i+1,nxt[i]>i+2,0,l!=nxt[i]-1)];
		}else{
			if(l==nxt[i]){
				res+=f[nxt[i]][get_id(nxt[i]>i+1,nxt[i]>i+2,1,0)];
			}else{
				res+=f[nxt[i]][get_id(nxt[i]>i+1,nxt[i]>i+2,0,l!=nxt[i]-1)];
			}
		}
	}else{
		int l=(j==4?nxt[i-1]:i);
		res+=nxt[i]-l;
		if(l==nxt[i]) return;
		res+=f[nxt[i]][get_id(nxt[i]>i+1,nxt[i]>i+2,1,0)];
	}
	return;
}
ll X[N],Y[N],D;
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<K;j++) f[i][j]=0;
	}
	nxt[0]=1;
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&X[j+1]-X[i]<=D) ++j;
		nxt[i]=j;
//		cout<<j<<endl;
	}
	for(int i=0;i<K;i++) f[n][i]=0;
	for(int i=n-1;i>=1;i--){
		for(int j=0;j<K;j++) get(i,j);
	}
	for(int i=1;i<=n;i++){
		ans+=f[i][0];
//		cout<<ans<<endl;
	}
}
void Main(){
	n=read();D=read();ans=0;
	for(int i=1;i<=n;i++) Y[i]=X[i]=read();
	int nn=n;
	for(int l=1,r;l<=nn;l++){
		r=l;
		while(r<nn&&Y[r+1]-Y[r]<=D) ++r;
		for(int i=l;i<=r;i++) X[i-l+1]=Y[i];
		n=r-l+1;
		solve();
//		cout<<l<<' '<<r<<' '<<ans<<endl;
		l=r;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int Cid=read(),T=read();
	while(T--) Main();
	cerr<<1.0*clock()/CLOCKS_PER_SEC<<"s"<<endl;
	return 0;
}
