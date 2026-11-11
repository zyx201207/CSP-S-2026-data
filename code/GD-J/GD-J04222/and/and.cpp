#include<bits/stdc++.h>
#define elif else if
//#define int long long
using namespace std;
int n,m,a[114514*2][31],ans,ok[114514*2],mi[114];
void input(){
	memset(ok,1,sizeof(ok));
	mi[0]=1;
	for(int i=1;i<=30;i++) mi[i]=mi[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		for(int j=0;x;x>>=1,j++) a[i][j]=x&1;
	}
}
void solve(){
	input();
	for(int j=30;j>=0;j--){
		int sum=0;
		for(int i=1;i<=n;i++) if(ok[i]) sum+=a[i][j];
		if(sum>=m){
			ans+=mi[j];
			for(int i=1;i<=n;i++) if(ok[i]) ok[i]=a[i][j];
		}
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}//Trick||Treat!
