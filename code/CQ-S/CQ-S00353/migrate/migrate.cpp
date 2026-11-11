#include<bits/stdc++.h>
#define int long long
//注意到每次这个鸟都是选最远的去雷霆大跳
//这样可以很快的求出最短的长度
//但是方案数
//其实不用考虑
//只需要看有没有次大就行了
//并且没有次次大
//首先，看到雷霆题面，我们发现不保证联通，所以要分成小块
//先找极小对，然后往外扩
//你每次直接记录一下dp，当你遇到一个点=2时，你直接清空。如果直接>2了，
//我旁边的人正在施法诅咒，实在是太不好了
//哎呀，打n^2吧，反正有200了 
using namespace std;
int c,t,n;
using ll=long long;
ll d,val[20010];
int cf[20010],mx[20010],dp[20010];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=1;i<=n;i++){
		int r=i;
		for(int j=i;j<=n;j++){
			if(val[j]-val[i]<=d)r=j;
			else break;
		}
		mx[i]=r;
		//cout<<mx[i]<<' ';
	}int ans=0;//cout<<'\n';
	for(int i=1;i<n;i++){
		if(mx[i]==i)continue;
		for(int j=1;j<=n;j++)cf[j]=0;
		int l=i+1,r=mx[i],now=1;
		int sum=0;
		cf[l]++;
		cf[r+1]--;
		for(int j=l;j<=r;j++)dp[j]=1;
		for(int j=i+1;j<=n;j++){
			
			sum+=cf[j];
			//cout<<dp[j]<<' '<<sum<<'\n';
			if(sum==2)ans++;
			//if(sum>2)break;
			if(j==mx[j])break;
			if(dp[j]==now){
				now++;
				l=r+1;
			}
			int tmp=r+1;
			r=mx[j];
			if(l<=r)cf[l]+=sum,cf[r+1]-=sum;
			for(int k=tmp;k<=r;k++)dp[k]=now;
		}//cout<<'\n';
	}
	cout<<ans<<'\n';
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdin);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

