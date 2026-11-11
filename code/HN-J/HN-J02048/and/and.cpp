#include<bits/stdc++.h >
using namespace std;
int k[200005];
int n,m,ans=0;
bool fsq=1;
int sq(int xxx){
	while(1){
		if(xxx==2)return 1;
		if(xxx%2!=0)return 0;
		xxx/=2;
	}return 1;
}
int ad(int af,int bf) {
	int aaaa=1,aaans=0;
	while(1) {
		if(af==0||bf==0)break;
		if(af%2==1&&bf%2==1) {
			aaans+=aaaa;
		}
		aaaa*=2;
		af/=2;
		bf/=2;
	}
	return aaans;
}
void dfs(int a,int b,int c) { //选了几个，选到了第几个，目前是多少
	if(a==m&&b<=n) {
		ans=max(ans,c);
		cout<<a<<"   "<<b<<"   "<<c<<" "<<ad(c,k[b])<<endl;
		return;
	}
	if(b>n||a>m)return;
	cout<<a<<" "<<b<<" "<<c<<" "<< ad(c,k[b]);
	cout<<endl;
	dfs(a,b+1,c);
	dfs(a+1,b+1,ad(c,k[b+1]));
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		if(sq(k[i]+1)==0)fsq=0;
	}
	if(fsq){
		sort(k+1,k+1+n);
		cout<<k[n-2];
	}
	else{
		dfs(0,1,2e30-1);
		cout<<ans;
	}
	return 0;
}
