#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bitset<N>mp[35];
bool flg[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int k=i+1;k<=30;k++){
			if(flg[k]){
				mp[i]|=mp[k];
			}
		}
		for(int j=1;j<=n;j++){
			if(mp[i][j]) continue;
			if((1<<i)&a[j]) cnt++,mp[i][j]=0;
			else mp[i][j]=1;
		}
		if(cnt<m) mp[i]=0;
		else{
			flg[i]=1,ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
