#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define ll long long

ll n,m;

ll a[N];

bool check2(int l,int r){
	ll maxn=a[l];
	for(int i=l+1;i<=r;i++){
		maxn=max(maxn,a[i]);
	}
	ll ans=0;
	for(int i=l;i<=r;i++){
		ans+=(maxn-a[i]);
		if(ans>m) return false;;
	}
	return true;
}

bool check1(int x){
	for(int i=1;i+x-1<=n;i++){
		if(check2(i,i+x-1)) return true;
	}
	return false;
}

bool checkdc(int x){
	ll ans=0;
	for(int i=1;i+x-1<=n;i++){
		ans=(a[i+x-1]-a[i])*x/2;
		if(ans<=m) return true;
	}
	return false;
}

void solvedch(){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(checkdc(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000){
		solvedch();
		return 0;
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check1(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
