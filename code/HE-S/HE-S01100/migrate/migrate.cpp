#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+5;
int c,t;
int n,k;
int a[N];
int nxt[N],pre[N],to_a[N],ans[N];
signed main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		int to=n-1;
		for(int i=n;i>=1;i--){
			if(to==i) to--;
			while(a[i]-a[to]<=k&&to>=1){
				to--;
			}pre[i]=i-to-1;
		}to=2;
		for(int i=1;i<=n;i++){
			if(to==i) to++;
			while(a[to]-a[i]<=k&&to<=n){
				to++;
			}nxt[i]=to-i-1;
		}for(int i=1;i<=n;i++) {
			if(pre[i]==1){
				to_a[i]=i-1;
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<nxt[i]<<' '<<pre[i]<<"\n";
//		}
		for(int i=1;i<=n;i++){
			if(nxt[i]==0) continue;
			int j=nxt[i]+i+1;
			if(j>n) continue;
			while(1){
				if(j>nxt[i+nxt[i]-1]+i+nxt[i]-1) break;
				int cnt=0;
				int p=i+1;
				while(nxt[p]+p<=j){
					cnt++;
					p++;
//					cout<<"k"<<cnt<<"\n";
				}if(cnt<2) ans[i]++;
				j++;
			}
		}int sum=0;
		for(int i=1;i<=n;i++){
			sum+=ans[i];
		}cout<<sum/2<<"\n";
		for(int i=1;i<=n;i++) {
			a[i]=0;
			ans[i]=0;
			nxt[i]=0;
			pre[i]=0;
		}
	}
	return 0;
}
