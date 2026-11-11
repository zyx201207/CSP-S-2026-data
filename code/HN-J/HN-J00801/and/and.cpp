#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[1000000];
void solve6(){
	int o=1;
	for(int i=1;i<=30;i++){
		o*=2;
	}
	bool l[1000000];
	int cnt;
	for(int i=30;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]>=o&&l[j]==0){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=o;
			for(int j=1;j<=n;j++){
				if(a[j]<o){
					l[j]=1;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j]>=o){
				a[j]-=o;
			}
		}
		o/=2;
	}
	cout<<ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	solve6();
	return 0;
}
