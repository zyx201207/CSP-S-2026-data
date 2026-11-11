#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int dp_[20005][20005];
long long ans;
void dp(int x,int y){
	dp_[x][y]=x&y;
	dp_[y][x]=y&x;
	ans=max(dp_[x][y],dp_[y][x]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			dp(a[i],a[j]);
		}
	}
	cout<<ans;
	return 0;
}

