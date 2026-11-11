#include<bits/stdc++.h>
using namespace std;
int N[200005];
bool flag[200005];
int cnt[22];
int n,m;
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>N[i];
	for(int i=1;i<=n;i++){
		for(int j=0;(1<<j)<=N[i];j++){
			if(N[i]&(1<<j)) cnt[j]++;
		}
	}
	for(int i=22;i>=0;i--){
		if(cnt[i]>=m){
			for(int j=1;j<=n;j++){
				if(!(N[j]&(1<<i))&&!flag[j]){
					for(int t=0;(1<<t)<=N[j];t++){
						if(N[j]&(1<<t)) cnt[t]--;
					}
					flag[j]=1;
				}
			}
			ans+=(1<<i);
		}
	}
	cout<<ans<<endl;
	return 0;
} 
