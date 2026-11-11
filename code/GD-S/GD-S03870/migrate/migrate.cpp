#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000006;
const int INF=1000000000000000000;
struct Node{
	int a,b,c;
}tr[N],a[N];
Node op(Node x,Node y){
	x.c=min(max(max(x.a,y.a),min(x.b,y.b)),min(max(x.b,y.b),min(x.c,y.c)));
	x.b=min(max(x.a,y.a),min(x.b,y.b));
	x.a=min(x.a,y.a);
	return x;
}
int read(){
	char c;int s=0,f=1;
	while(!isdigit(c)){
		c=getchar();
		if(c=='-') f=-1;
	}
	while(isdigit(c)){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
}
int x[N],n,d,c,t,ans,lst[N],s1[N],ss[N];
void add(int x,Node w){
	for(int i=x;i<=n;i+=i&(-i)) tr[i]=op(tr[i],w);
}
Node sum(int x){
	Node tmp={INF,INF,INF};
	for(int i=x;i>0;i-=i&(-i)) tmp=op(tmp,tr[i]);
	return tmp;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	if(c<=10){ 
		while(t--){
			n=read();d=read();ans=0;
			for(int i=1;i<=n;i++) x[i]=read();
			for(int i=1;i<=n;i++){
				int l=i,r=n;lst[i]=i;
				while(l<=r){
					int mid=(l+r)>>1;
					if(x[mid]<=d+x[i]) l=mid+1,lst[i]=mid;
					else r=mid-1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) tr[j]={INF,INF,INF};
				for(int j=i;j<=n;j++){
					if(i==j) a[j]={0,INF,INF};
					else a[j]=sum(n-j+1);
					if(a[j].a==a[j].b&&a[j].b<a[j].c) ans++;
					a[j].a++;a[j].b++;a[j].c++;
					add(n-lst[j]+1,a[j]);
				}
			}
			cout<<ans<<"\n";
		}
	} 
	else if(c<=12){
		while(t--){
			n=read();d=read();ans=0;
			for(int i=1;i<=n;i++) x[i]=read();
			for(int i=1;i<=n;i++){
				int l=i,r=n;lst[i]=i;
				while(l<=r){
					int mid=(l+r)>>1;
					if(x[mid]<=d+x[i]) l=mid+1,lst[i]=mid;
					else r=mid-1;
				}
			}
			for(int j=1;j<=n;j++) tr[j]={INF,INF,INF};
			for(int j=1;j<=n;j++){
				if(j==1) a[j]={0,INF,INF};
				else a[j]=sum(n-j+1);
				if(a[j].a==a[j].b&&a[j].b<a[j].c) ans+=(n-j+1);
				a[j].a++;a[j].b++;a[j].c++;
				add(n-lst[j]+1,a[j]);
			}
			cout<<ans<<"\n";
		}
	}
	else if(c<=14){ 
		while(t--){
			n=read();d=read();ans=0;
			for(int i=1;i<=n;i++) x[i]=read(),s1[i]=0;
			for(int i=1;i<=n;i++){
				int l=i,r=n;lst[i]=i;
				while(l<=r){
					int mid=(l+r)>>1;
					if(x[mid]<=d+x[i]) l=mid+1,lst[i]=mid;
					else r=mid-1;
				}
				s1[i]+=s1[i-1]+1;s1[lst[i]+1]--;
				ss[i-s1[i]+1]++;
			}
			for(int i=1;i<=n;i++) ans+=ss[lst[i]-1];
			cout<<ans<<"\n";
		}
	}
	else while(t--) cout<<"0\n";
	return 0;
}
