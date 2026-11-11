#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans;
bool bit[200005][35],choose[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<30;j++){
			if((a[i]&(1<<j))!=0) bit[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++) choose[i]=1;
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(choose[j]==1&&bit[j][i]) cnt++;
		}
		if(cnt>=m){
			ans+=(1<<i);
			for(int j=1;j<=n;j++){
				if(bit[j][i]==0) choose[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
