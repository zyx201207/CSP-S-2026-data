#include<bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
const int N=505,M=5e4+5;
int c,n,m,d,q,w[M]={0},a[N][M]={0},t[N][M]={0},k[N]={0},lian1[N][M]={0};
bool lian[N][M]={0};//第i条线路是否连接第j个站
long long bfs(int nowxianlu,int now,int end){
	for(int i=1;i<=k[nowxianlu];i++){
		if(a[nowxianlu][i]==end){
			return t[nowxianlu][i];
		}
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	file("subway");//不要注释，检查文件名  
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j],lian[i][a[i][j]]=1,lian[i][a[i][j]]=t[i][j];
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		long long ans=1e9;
		for(int i=1;i<=n;i++){
			if(lian[i][l]==1){
				ans=lian1[i][l]+min(ans,bfs(i,l+1,r));
			}
		}
		ans+=w[l]+w[r];
		cout<<ans<<endl;
	}
	return 0;
}


