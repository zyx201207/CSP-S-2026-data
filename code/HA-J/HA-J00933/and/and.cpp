#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],sum,ans;
int cnt[40],vis[N];
int main(){
	//¹Ø×¢luogu 1406766 Ð»Ð»ß÷
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	sum=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0) continue;
			if(((a[j]>>i)&1))cnt++;
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(vis[j]==0) continue;
				if(((a[j]>>i)&1)==0)vis[j]=0,sum--;
			}
			//cout<<(1<<i)<<"\n";
			ans=ans+(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
/*
1 1
1
*/

