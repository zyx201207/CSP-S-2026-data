#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],mx=-1,n,m,b[200010],q=0;
void dfs(int x){
	int sum=b[1];
	q++;
	if(x==m+1){
		for(int i=2;i<=m;i++)sum&=b[i];
		if(sum>mx)mx=sum;
		return;
	}
	for(int i=x;i<=n;i++){
		b[x]=a[i];
		dfs(x+1);
	}
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	dfs(1);
	cout<<mx;
	return 0;
}
