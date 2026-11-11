#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,t; 
int n,m,a[2000001],rht[2000001],lft[2000001],f[501][501],an[501][501];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];lft[i]=n+1;
		}
		int l=1;
		for(int i=1;i<=n;i++){
			while(l<=n&&a[l]-a[i]<=m) l++;
			rht[i]=l-1;
			lft[l-1]=min(lft[l-1],i);
		}
		if(T<=6){
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					f[i][j]=0x3f3f3f3f;
					an[i][j]=0;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=m){
						f[i][j]=1;
						an[i][j]=1;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int k=j+1;k<=n;k++){
						if(f[i][k]==f[i][j]+f[j][k]) an[i][k]=min(3ll,an[i][k]+an[i][j]*an[j][k]);
						else if(f[i][k]>f[i][j]+f[j][k]) f[i][k]=f[i][j]+f[j][k],an[i][k]=min(3ll,an[i][j]*an[j][k]);
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans+=(an[i][j]==2);
				}
			}
			cout<<ans<<"\n";
			continue;
		}
		if(T==11||T==12||T==13||T==14){
			int ans=0;
			for(int i=1;i<=n;i++){
				int mx=rht[i];
				int mxx=rht[mx-1];
				int l=mx+1,r=mxx,val=INT_MAX;
	//			cout<<mx<<" "<<mxx<<' '<<l<<" "<<r<<"\n";
				while(l<=r){
					int mid=l+r>>1;
					if(lft[mid]==mx-1) r=mid-1,val=mid;
					else l=mid+1;
				}
				ans+=max(0ll,mxx-val+1);
			}
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}
/*
可以发现，随着点往后走，最短路径的条数一定会变多。

首先排除掉一步就能跳到的这部分区间。

欸你可以对每个点维护一个区间，然后如果这两个点的区间的交集刚好等于二，就说明这两个点是一个答案。

那么题意就转化为，对于 n 个区间，找到有几组区间的交区间长度刚好为 2。

这个很数据结构啊。

好像你可以对每个点直接二分端点说是，那这不就做完了。 

现在是 15:57 写一个看看实力。 

假了，区间可合并。 

打暴力了 
0 1
5 3
-3 0 2 3 4
*/

