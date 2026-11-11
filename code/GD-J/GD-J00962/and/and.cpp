#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],z[N][33],vis[N];
int n,m;
void jzh(int i,int x){
	int m=__lg(x);
	int cnt=1;
	for(int j=1;j<=m;j++){
		cnt*=2; 
	}
	for(int j=m;j>=0&&x>0;j--,cnt/=2){
		if(x-cnt>=0){
			x-=cnt;
			z[i][j]++;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		jzh(i,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=32;j>=0;j--){
			cout<<z[i][j];
		}
		cout<<endl;
	}
	for(int j=32;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==0&&z[i][j]==1)cnt++;
		}
		if(cnt>=m){
			z[0][j]=1;
			for(int i=1;i<=n;i++){
				if(z[i][j]==0){
					vis[i]=1;
				}
			}
		}else {
			z[0][j]=0;
		}
	}
	int ans=0,cnt=1;
	for(int j=0;j<=32;j++,cnt*=2){
		if(z[0][j]==1)ans+=cnt; 
	}
	cout<<ans;
	return 0;
} 
