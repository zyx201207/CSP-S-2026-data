#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+9;
const int Min_N=5009;
int c,t;
int n;
ll d;
ll a[N];
ll f[Min_N][Min_N];
int l[Min_N][Min_N];
void run1(){
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=0;
			l[i][j]=1e9;
		}
		l[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]>d)break;
			l[i][j]=1;f[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			for(int k=j+1;k<i;k++){
				if(a[i]-a[k]>d)continue;
				if(l[j][i]>l[j][k]+1){
					l[j][i]=l[j][k]+1;
					f[j][i]=f[j][k];
				}
				else if(l[j][i]==l[j][k]+1){
					f[j][i]=f[j][i]+f[j][k];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][j]==2){
//				cout<<l[i][j]<<" ";
//				cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
void run2(){
	ll D=a[2]-a[1];
	ll gs=d/D;
	ll ans=0;
	if(gs==0||gs==1){
		cout<<0<<endl;
		return;
	}
	for(int i=2*gs;i<=n;i++){
		ans++;
	}
	cout<<ans<<endl;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1){
		cout<<0<<endl;
		return;
	}
	ll lst=a[2]-a[1];
	bool p=1;
	for(int i=3;i<=n;i++){
		if(lst!=a[i]-a[i-1])p=0;
	}
	if(n<=5000)run1();
	else if(p)run2();
	else cout<<0<<endl;
//	run2();
}
int main(){
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
} 
/*
10 3
0 3 6 7 8 9 10 13 16 19
*/
