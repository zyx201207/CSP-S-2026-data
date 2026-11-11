#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005],bit[200005][70],pre[200005],b[200005],mp[70];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],cnt=-1;
		if(!x){
			bit[i][0]=0;
			continue;
		}
		while(x){
			bit[i][++cnt]=x%2;
			x>>=1;
		}
	}
	for(int i=50;i>=0;i--){
		for(int j=1;j<=n;j++){
			if(bit[j][i]){
				mp[i]++;
			}
		}
	}
	int cnt=n,ans=0;
	for(int i=50;i>=0;i--){
		if(mp[i]>=m){
			ans+=(1ll<<i);
			int cnt0=0,cnt1=0;
			for(int j=1;j<=cnt;j++){
				if(((a[j]>>i)&1)){
					pre[++cnt0]=a[j];
				}else{
					b[++cnt1]=a[j];
				}
			}
			for(int j=1;j<=cnt0;j++){
				a[j]=pre[j];
			}
			cnt=cnt0;
			for(int j=i-1;j>=0;j--){
				for(int k=1;k<=cnt1;k++){
					if(((b[k]>>j)&1)){
						mp[j]--;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
