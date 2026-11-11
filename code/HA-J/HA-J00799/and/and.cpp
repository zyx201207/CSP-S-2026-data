#include<bits/stdc++.h>
using namespace std;
long long cnt[40],p[200005][32],vis[200005],n,m,mx,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		while(x){
			p[i][++cnt[i]]=x%2;
			x/=2;
		}
		mx=max(mx,cnt[i]);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=cnt[i];j++)cout<<p[i][j];
//		cout<<endl;
//	}
	for(int i=mx;i>=1;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(p[j][i]){
				vis[j]=1;
				sum++;
			}
		}
		if(sum>=m){
			mx=i;
			break;
		}
	}
	
	for(int i=mx;i>=1;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(p[j][i]&&vis[j])sum++;
		}
		if(sum>=m){
			for(int k=1;k<=n;k++){
				if(p[k][i]==0)vis[k]=0;
			}
			ans+=int(pow(2,i-1));
		}
//		cout<<sum<<" ";
	}	
	cout<<ans;
	return 0;
}

