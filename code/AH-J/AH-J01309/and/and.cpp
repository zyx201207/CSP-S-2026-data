#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int dp[60],n,a[N],k;
bool cmp(int x,int y) {
	int dx[60],dy[60],lenx=0,leny=0;
	memset(dx,0,sizeof dx);
	memset(dy,0,sizeof dy);
	while(x){
		dx[lenx++]=x%2;
		x/=2;
	}
	while(y) {
		dy[leny++]=y%2;
		y/=2;
	}
	lenx--,leny--;
	for(int i=max(lenx,leny);i>=0;i--) {
		if(dx[i]==0&&dy[i]==1&&dp[i]>1) return 0;
		if(dx[i]==1&&dy[i]==0&&dp[i]>1) return 1;
	}
	return 0;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		for(int j=0;j<40;j++) {
			if((a[i]>>j)&1) {
				dp[j]++;
			}
		}                      
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=k;i++) ans=ans&a[i];
	cout<<ans;
	return 0;
}


