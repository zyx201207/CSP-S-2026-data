#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],ans=0;
ll cost(int x,int y){
	return a[x]-a[y];
}
ll scost(int x){
	ll s=0,len=0;
	for(int i=x;i>=1&&(s+a[x]-a[i])<=m;i--){
		s+=a[x]-a[i];
		len++;
	}
	return len;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int last=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans=max(ans,scost(i));
	}
	cout<<ans;
	return 0;
}
