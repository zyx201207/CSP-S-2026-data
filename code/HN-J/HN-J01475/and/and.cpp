#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N];
int b[N];
int sk[N][40];
int ans;
int flag[N];
int curk;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int k=0;k<=31;k++){
		for(int i=1;i<=n;i++){
			if(a[i]%2==1) sk[i][k]=1;
			a[i]/=2;
		}
	}
	for(int i=1;i<=n;i++) flag[i]=1;
	for(int k=31;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(flag[i]&&sk[i][k]) cnt++;
		}
		if(cnt>=m){
			ans+=(1LL<<k);
			for(int i=1;i<=n;i++){
				if(sk[i][k]==0){
					flag[i]=0;
				}
			}
		}
	}
	cout<<ans;
	return ;
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int oT_To=1;
//   cin>>oT_To;
	while(oT_To--) solve();
	return 0;
}
