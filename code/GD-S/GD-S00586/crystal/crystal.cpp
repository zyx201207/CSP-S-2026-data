#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10;
using ll=long long;
int n,l,r,mid;
ll m,a[N],sm[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(sm[i]-sm[i-x]+m>=a[i]*x)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sm[i]=sm[i-1]+a[i];
	l=1,r=n;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<'\n';
}