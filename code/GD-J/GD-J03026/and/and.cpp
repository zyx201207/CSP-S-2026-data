#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int a[N],f[N];
int n,m;
bool cmp(int l,int r){
	return l>r;
}
int dfs(int l,int x,int j){
	int cnt=0;
	if(n-l+1<m-j){
		return 0;
	}
	if(j>m){
		return x;
	}
	for(int i=l;i<=n;i++){
		int y=x&a[i];
		cnt=max(cnt,dfs(i+1,y,j+1));
	}
	return cnt;
}
signed main(){
	int cnt=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cnt=max(cnt,dfs(i,a[i],1));
	}
	cout<<cnt;
	return 0;
} 
