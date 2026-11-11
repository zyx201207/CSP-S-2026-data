#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a,f[35][200005],ch[200005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		int k=0;
		while(a>0) f[++k][i]=a%2,a=a/2;
	}
	int ans=0;
	for(int i=31;i>=1;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(f[i][j]==1 && ch[j]==0) cnt++;
		}
		ans=ans*2+(cnt>=m);
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(f[i][j]==0) ch[j]=1;
			}
		}
	}
	cout<<ans;
	return 0; 
}
