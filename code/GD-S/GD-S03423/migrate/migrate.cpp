#include<bits/stdc++.h>
#define ll long long 
#define fg cout<<"！！！！！！！！！！！！！！！！！！！！！！！！！！"<<endl
#define inf (ll)1e18
#define pb push_back
#define mk make_pair
#define pii pair<ll,ll>
using namespace std;
const int mod=998244353,N=2e6+5;
int M1;
ll read(){
	ll n=0,k=1;
	char c;
	while(c>'9'||c<'0'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+c-'0';
		c=getchar();
	}
	return n*k;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
ll n,d;
ll a[N],L[N],R[N],ans,f[N],g[N];
ll c[N];
int dep[N],cnt[N];
int solve(int x){
	for(int i=1;i<=n;i++) dep[i]=1145141919,cnt[i]=1145141919;
	queue<int>q;
	q.push(x);
	dep[x]=0;cnt[x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=L[u];i<u;i++){
			if(dep[i]>dep[u]+1){
				dep[i]=dep[u]+1;
				cnt[i]=cnt[u];
				q.push(i);
			}else if(dep[i]==dep[u]+1) cnt[i]+=cnt[u];
		}
	} 
	int res=0;
	for(int i=1;i<=x;i++){
		if(cnt[i]==2) res++;
	}
	return res;
}
void For_aiur(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(i==1) L[i]=i;
		else L[i]=L[i-1];
		while(a[i]-a[L[i]]>d) L[i]++;
	}
	for(int i=n;i>=1;i--){
		if(i==n) R[i]=i;
		else R[i]=R[i+1];
		while(a[R[i]]-a[i]>d) R[i]--;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		f[i]=0;
		f[i]=solve(i);
	}
	for(int i=1;i<=n;i++){
		ans+=f[i];
	}
	cout<<ans<<endl;
}
int M2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();cin.tie();cout.tie();
	int wlae=1,C;
	cin>>C;
	cin>>wlae;
	while(wlae--) For_aiur();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
