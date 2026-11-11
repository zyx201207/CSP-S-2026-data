#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxn=0;
int gs(int x){
	int cnt=0;
	while(x>0){
		cnt+=x%2;
		x/=2;
	}
	return cnt;
}
bool cmp(int a,int b){
	return gs(a)>gs(b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	maxn=a[1];
	for(int i=2;i<=m;i++){
		maxn=maxn&a[i];
	}
	cout<<maxn;
	
	return 0;
}
