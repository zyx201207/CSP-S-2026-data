#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int n;
ll m;
ll a[N],b[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		int l=i-x+1;
		ll res=(a[i]*x)-(b[i]-b[l-1]);
		if(res<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		b[i]+=b[i-1];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
