#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll a[N],ans;
int n,m;
bool vis[N],vis1[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	//思路：2^i>sum(2^1,2^i-1)
	int bitcnt=0;
	int i=30;
	for(;i>=0;i--){//求出第一个满足数量的bit 
		for(int j=1;j<=n;j++){
			if(a[j]&(1ll<<i))bitcnt++,vis[j]=1;
		}
		if(bitcnt<m){
			memset(vis,0,sizeof vis);
			bitcnt=0;
		} 
		else {
			ans+=(1ll<<i);
			break;
		}
	}
	i-=1;
	for(;i>=0;i--){//往下遍历，继续找出额外可以提供的bit 
		int nowcnt=bitcnt;
		for(int j=1;j<=n;j++){
			vis1[j]=vis[j];
			if(!vis1[j])continue;
			if(!(a[j]&(1ll<<i)))nowcnt--,vis1[j]=0;
		} 
		if(nowcnt>=m){
			bitcnt=nowcnt;
			for(int j=1;j<=n;j++)vis[j]=vis1[j];
			ans+=(1ll<<i);
		}
	}
	cout<<ans;
	return 0;
}
