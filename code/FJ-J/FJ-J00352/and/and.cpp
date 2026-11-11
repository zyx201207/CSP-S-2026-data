#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[200010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	stable_sort(a+1,a+n+1,cmp);
	b[0]=2147483647;
	for(int i=1;i<=n;++i){
		b[i]=b[i-1]&a[i];
	}
	int ans=1;
	for(int i=m;i<=n;++i){
		ans=max(ans,b[i]&b[i-m]);
	}
	cout<<ans<<endl;
	return 0;
}

