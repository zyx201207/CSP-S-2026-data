#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_back pb
#define first fi
#define second se 
int n,m,use[200005],a[200005][50],aa,cnt,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa;
		for(int k=0;k<=30;k++){
			if(aa&(1<<k)){
				a[i][k]=1;
			}
		}
	}
	for(int i=30;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(!use[j])cnt+=a[j][i];
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!a[j][i])use[j]=1;
			}
			ans+=1<<i;
		}
	}
	cout<<ans;
	return 0;
}
