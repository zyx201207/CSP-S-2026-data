#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],cnt[35],ans;
bool bl[200005][35],bll[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=29;j++){
			if(a[i]&1){
				bl[i][j]=true;
				cnt[j]++;
			}
			else{
				bl[i][j]=false;
			}
			a[i]/=2;
		}
	}
	for(int j=29;j>=0;j--){
		if(cnt[j]>=m){
			ans+=(1<<j);
			for(int i=1;i<=n;i++){
				if(!bl[i][j]&&!bll[i]){
					bll[i]=true;
					for(int q=0;q<=29;q++){
						if(bl[i][q]){
							cnt[q]--;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
