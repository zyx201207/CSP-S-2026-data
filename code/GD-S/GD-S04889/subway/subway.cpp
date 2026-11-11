#include<bits/stdc++.h>
using namespace std;
int w[500005],A[500005],B[500005];
vector<int> a[500005],t[500005];
int ans=1e9;
bool b[5005][5005];
int f(int x,int y,int T){
	b[x][y]=1;
	if(a[x][y]==y)return T;
	for(int i=0;i<a[x].size();i++){
		if(b[x][i]==0){
			ans=min(ans,f(a[x][i],y,T+t[x][i]));
			b[x][i]=0;
		}
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		cin>>A[1]>>B[1];
		for(int j=2;j<=k;j++){
			cin>>A[j]>>B[j];
			a[A[j]].push_back(A[j-1]);
			a[A[j-1]].push_back(A[j]);
			a[A[j]].push_back(B[j-1]);
			a[A[j-1]].push_back(B[j]);
		}
		if(c>=7&&c<=11){
			int mn=1e9,mnn=1e9;
			for(int j=1;j<=k;k++){
				if(B[j]<=mn){
					mnn=mn;
					mn=B[j];
				}else if(B[j]<=mnn){
					mnn=B[j];
				} 
			}
			for(int i=1;i<=m;i++)cout<<mn+mnn<<endl;
			return 0;
		}
	}
	for(int i=1;i<=q;i++){
		ans=1e9;
		int x,y;cin>>x>>y;
		cout<<f(x,y,0)<<endl;
	}
}
