#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=2147483647,c[35];
bool b[200005][35],f;
void dfs(int idx,int k,int s){
//	cout<<idx<<" "<<k<<" "<<s<<"\n";
	if(k==m){
		ans=max(ans,s);
		return;
	}
	if(idx>n) return;
	if(n-idx+1>m-k) dfs(idx+1,k,s);
	dfs(idx+1,k+1,s&a[idx]);
}
bool cmp(int a,int b){
	return __builtin_popcount(a)>__builtin_popcount(b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		int idx=0,x=a[i];
//		while(x){
//			b[i][++idx]=x&1;
//			c[idx]+=x&1;
//			x>>=1;
//		}
	}
//	for(int i=31;i>=1;i--){
//		if(c[i]==m){
//			for(int j=1;j<=n;j++){
//				if(b[j][i]) ans&=a[j];
//			}
//			f=1;
//			break;
//		}
//	}
//	if(f) cout<<ans;
////	else if()
//	else{
		ans=0;
		dfs(1,0,2147483647);
		cout<<ans;
//	}
	
	return 0;
}

