#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=2e5+5;

int n,m;
ll a[N];

bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	n=unique(a+1,a+1+n)-a-1;
	ll ans=a[1];
//	cout<<ans<<'\n';
	for(int i=2;i<=m;i++){
//		cout<<a[i]<<'\n';
		ans&=a[i];
	}
	cout<<(ans==0?a[2]:ans);
	return 0;
}
