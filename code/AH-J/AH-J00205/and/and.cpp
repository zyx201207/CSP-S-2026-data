#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int b[200005][35];
int ans[35];
int cnt[35];
int sum[35];
int p[200005],tot;
int vis[200005];
int st;
int ssum;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int op=a[i],j=1;
		while(op){
			b[i][j]=(op&1);
			if(b[i][j]){
				cnt[j]++;
			}
			op>>=1;
			j++;
		}
	}
	for(int i=30;i>=1;i--){
		if(cnt[i]>=m){
			st=i;
			break;
		}
	}
	if(st==0){
		cout<<0;
		return 0;
	}
	for(int i=st;i>=1;i--){
		if(i==st){
			for(int j=1;j<=n;j++){
				if(b[j][i]==1){
					p[++tot]=j;
					for(int k=1;k<=30;k++){
						sum[k]+=b[j][k];
					} 
				} 
			}
		}
		else if(sum[i]>=m){
			for(int j=1;j<=tot;j++){
				if(vis[j]) continue;
				if(b[p[j]][i]==0){
					vis[j]=1;
					for(int k=1;k<=30;k++){
						sum[k]-=b[p[j]][k];
					}
				}
			}
		}
	}
	memset(ans,1,sizeof(ans));
	for(int i=1;i<=tot;i++){
		if(vis[i]) continue;
		for(int j=1;j<=30;j++){
			ans[j]=(ans[j]&b[p[i]][j]);
		}
	}
	int kp=1;
	for(int i=1;i<=30;i++){
		ssum+=kp*ans[i];
		kp<<=1;
	}
	cout<<ssum;
	return 0;
} 
