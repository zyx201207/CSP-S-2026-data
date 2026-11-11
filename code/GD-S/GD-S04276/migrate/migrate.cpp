#include<bits/stdc++.h>//Çå¿Õ¶à²â 
using namespace std;
#define int long long
const int inf=2e18;
const int N=2e6+5;
bool st;
int n,d,a[N],l[N],r[N];
int f[N],ans,pre[N];
void calc(int st){
	for(int i=0;i<=n+1;i++) f[i]=inf;
	f[st]=0;
	int ed=st;
	for(int i=st+1;i<=n;i++){
		if(l[i]==i) break;
		f[i]=f[max(st,l[i])]+1;
		ed=i;
	}
	for(int i=ed;i>=1;i--){
		if(i==ed||f[i+1]!=f[i]) r[i]=i;
		else r[i]=r[i+1];
	}
//	cout<<st<<" "<<ed<<'\n';
//	for(int i=st+1;i<=ed;i++) cout<<f[i]<<" ";
//	cout<<'\n';
	pre[st]=1;
	pre[st-1]=0;
	for(int i=st+1;i<=ed;i++){
		int L=max(l[i],st);
		if(pre[r[L]]-pre[L-1]==2){
			ans++;
		}
		pre[i]=pre[i-1]+pre[r[L]]-pre[L-1];
//		cout<<i<<":"<<L<<" "<<r[L]<<" "<<pre[i]<<'\n';
	}
}
void sol_bl(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=2;i<=n;i++) cout<<a[i]-a[i-1]<<" ";
//	cout<<'\n';
	l[1]=1;
	for(int i=2;i<=n;i++){
		l[i]=l[i-1];
		while(a[i]-a[l[i]]>d) l[i]++;
	}
//	for(int i=1;i<=n;i++) cout<<l[i]<<" ";
	for(int i=1;i<=n;i++){
		calc(i);
	}
	cout<<ans<<'\n';
}
void sol_dc(){
	cin>>n>>d;
//	cerr<<n<<" "<<d<<'\n';
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		cerr<<i<<" ";
	}
	sort(a+1,a+n+1);
	if(n==1){cout<<0<<'\n';return;}
//	cerr<<a[2]<<" "<<a[1]<<'\n';
	int c=a[2]-a[1];
	d/=c;
//	cerr<<c<<" "<<d<<'\n';
	if(d==1||d==0){
		cout<<0<<'\n';
		return;
	}
	cout<<max(0ll,n-d*2+1)<<'\n';
}
bool ed;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	cerr<<(&st-&ed)/1024.0/1024.0;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	if(c<=10){
		while(T--) sol_bl();
	}
	else{
		while(T--) sol_dc();
	}
//	else {
//		while(T--) sol_o();
//	}
}
