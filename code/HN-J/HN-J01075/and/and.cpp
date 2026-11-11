#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int vis[N][35];
bool flag[N],nflag[N];
int ans[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		for(int j=30;j>=0;j--){
			if((1ll<<j)<=x){
				vis[i][j]=1;
				x-=(1ll<<j);
			}else{
				vis[i][j]=0;
			}
		}
	}
	long long res=n-m;
	for(int i=30;i>=0;i--){
		long long tmp=res;
		for(int j=1;j<=n;j++){
			nflag[j]=flag[j];
			if(vis[j][i]==0&&flag[j]==0){
				tmp--;
				nflag[j]=1;
			}
		}
		if(tmp>=0){
			res=tmp;
			ans[i]=1;
			for(int j=1;j<=n;j++){
				flag[j]=nflag[j];
				nflag[j]=0;
			}
		}
	}
	long long ans_res=0;
	for(int i=30;i>=0;i--){
		if(ans[i]==1){
			ans_res+=(1<<i);
		}
	}
	cout<<ans_res<<"\n";
	return 0;
}
/*
4 2
3 15 12 12
*/
