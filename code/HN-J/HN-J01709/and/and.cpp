#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
bool bit[200005][35];
bool f[200005];
bool choose[35];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if((a[i]>>j)&1){
				bit[i][j]=1;
			}
		}
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!f[j]&&bit[j][i]==1){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!f[j]&&bit[j][i]==0){
					f[j]=1;
				}
			}
			choose[i]=1;
		}
	}
	for(int i=30;i>=0;i--){
		if(choose[i]==1){
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
