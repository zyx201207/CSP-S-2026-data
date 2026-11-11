#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxx[500005],stb[500005][32],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(stb,-1,sizeof(stb));
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		stb[i][0]=0;
	}
	for (int i=1;(1<<i)<n;i++){
		for (int j=1;j+(1<<i)-1<=n;j++){
			stb[j][i]=stb[j][i-1]+stb[j+(1<<(i-1))][i-1]+(1<<(i-1))*(a[j+(1<<i)-1]-a[j+(1<<(i-1))-1]);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=30;j++){
			if (stb[i][j]>=0&&stb[i][j]<=m){
				maxx[i]=j;
			}
		}
	}
	for (int i=1;i<=n;i++){
		long long wd=1<<maxx[i], num=stb[i][maxx[i]];
		for (int j=maxx[i];j>=0;j--){
			if (stb[i+wd][j]==-1){
				continue;
			}
			int add=num+stb[i+wd][j]+wd*(a[i+wd+(1<<j)-1]-a[i+wd-1]);
			if (add<=m){
				num=add;
				wd+=1<<j;
			}
		}
		ans=max(ans,wd);
	}
	cout<<ans;
	return 0;
}
