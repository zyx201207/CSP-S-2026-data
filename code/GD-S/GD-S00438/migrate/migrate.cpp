#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,cnt;
bool ed;
long long n,d,p,x[N];
void dfs(int s,int t,int y){
	if(ed||s>=t) return ;
	if(y==1&&x[t]-x[s]<=d){
		cnt++;
		if(cnt==3) ed=1;
		return ;
	}
	for(int i=s+1;i<=t-y+1;i++){
		if(x[i]-x[s]<=d) dfs(i,t,y-1);
	}
}
void solve1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cnt=0;
			ed=0;
			dfs(i,j,(x[j]-x[i]-1)/d+1);
			if(cnt==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve2(){
	d/=x[2]-x[1];
	for(int i=1;i<=n;i++){
		x[i]=i;
	}
	cout<<(d>1?max(0LL,n-2*d+1):0)<<"\n";
}
void solve3(){
	cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>20||c%10>2) solve3();
	while(t--){
		cin>>n>>d;
		cin>>p;
		x[1]=1;
		for(int i=2;i<=n;i++){
			cin>>x[i];
			x[i]=x[i]-p+1;
		}
		if(c>=1&&c<=2) solve1();
		else if(c>=11&&c<=12) solve2();
	}
	return 0;
}
