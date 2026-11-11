#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define out() (cout<<"sb\n")

const int N=2e6+5;

int n,d,a[N],nxt[N];
int path[N];

int f(int i,int j){
	if(nxt[i]==i || nxt[j]==j || i==j) return 0;
	if(nxt[j]<=nxt[i]) return 0;
	return (nxt[j]-nxt[i])+f(nxt[i],nxt[j]);
}

void slv1(){
	int x=a[2]-a[1],step=d/x;
//	cout<<step<<"\n";
	if(step<2) {
		cout<<0<<"\n";
		return;	
	}
	int ans=0;
	for(int i=n-step;i>=1;i--){
		int j=i+2*step-1;
		if(j>n) continue;
		int len=n-j;
		ans++;
	}
	cout<<ans<<"\n";
}

bool check(int x,int y){
	if(y<=nxt[x]) return 0;
	int tot=1,u=x;
	path[1]=x;
	while(nxt[u]<y && u!=nxt[u]){
		path[++tot]=nxt[u];
		u=nxt[u];
	}
//	cout<<x<<' '<<y<<" "<<u<<" "<<path[tot]<<" "<<tot<<"\n";
	if(u==nxt[u] && u!=y) return 0;
	if(tot<=2){
		int p=path[tot];
//		cout<<p-2<<" "<<path[tot-1]<<' '<<a[y]-a[p-2]<<"\n";
		if(p-2>=path[tot-1] && a[y]-a[p-2]<=d) return 0;
//		cout<<x<<" "<<y<<"\n";
		return 1;
	} 
	int p=path[tot],q=path[tot-1],r=path[tot-2];
	if(p-2>=q && a[y]-a[p-2]<=d) return 0;
	if(a[y]-a[p-1]>d) return 0;
	if(q-1>=r && a[p-1]-a[q-1]<=d) return 0;	
//	cout<<x<<" "<<y<<"\n";
	return 1;
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool f1=1;
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[2]-a[1]) f1=0;
	if(f1) return slv1();
	nxt[n]=n;
	for(int i=n-1;i>=1;i--){
		int l=i,r=nxt[i+1];
		while(l<r){
			int mid=(l+r+1)>>1;
			if(a[mid]-a[i]<=d) l=mid;
			else r=mid-1;
		}
		nxt[i]=l;
	}
//	for(int i=1;i<=n;i++) cout<<nxt[i]<<" \n"[i==n];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=check(i,j);
		}
	}
	cout<<ans<<"\n";
}

signed main(){
//	system("fc migrate.in migrate.ans");
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	IOS;
	int T;
	cin>>T>>T;
	while(T--) solve();
	return 0;
}

