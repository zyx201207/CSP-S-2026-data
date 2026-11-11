#include<bits/stdc++.h>
using namespace std;
int dp[100005],a[100005];
bool b[100005];
int n,m;
int c[4];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==2&&n<=2000){
		int mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int num=a[i]&a[j];
				mx=max(mx,num);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,n);
		}
		cout<<mx;
		return 0;
	}
	if(n==m){
		for(int i=2;i<=n;i++)a[i]&=a[i-1];
		cout<<a[m];
		return 0;
	}
	if(n==m+1){
		int mx=0;
		for(int i=1;i<=n;i++){
			int num;
			if(i!=1)num=a[1];
			else num=a[2];
			for(int j=1;j<=n;j++){
				if(j!=i){
					num&=a[j];
				}
			}
			mx=max(mx,num);
		}
		cout<<mx;
		return 0;
	}
	int w=0;
	for(int i=1;i<=n;i++)w=max(w,a[i]);
	if(w<4){
		for(int i=1;i<=n;i++)c[a[i]]++;
		if(a[3]>=m)cout<<3;
		else if(a[2]>=m)cout<<2;
		else if(a[1]>=m)cout<<1;
		else cout<<1;
		return 0;
	}
	int num=0;
	for(int i=1;i<=n;i++){
		dp[1]=max(dp[i],a[i]);
		if(dp[1]<a[i]){
			dp[1]=a[i];
			b[num]=0;
			num=i;
			b[num]=1;
		}
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(b[j]==0){
				dp[i]=dp[i-1]&a[j];
				b[j]=1;
			}
		}
		int k=0;
		for(int j=2;j<=n;j++){
			if(b[j]==0){
				if(dp[i]<=dp[i-1]&a[j]){
					dp[i]=dp[i-1]&a[j];
					b[k]=0;
					k=j;
					b[k]=1;
				}
			}
		}
	}
	cout<<dp[m];
	return 0;
} 
