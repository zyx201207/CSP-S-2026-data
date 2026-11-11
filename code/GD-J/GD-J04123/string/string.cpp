#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5;
ll n,sum;
ll a[N];
ll lf[N],ri[N];
char c[N];
char str[300000005];
ll find_left(ll x){
	ll l = 1,r = n,mid,ret = 1;
	while(l<=r){
		mid = (l+r)/2;
		if(lf[mid]<=x){
			ret = mid;
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
	return ret;
}
ll find_right(ll x){
	ll l = 1,r = n,mid,ret = n;
	while(l<=r){
		mid = (l+r)/2;
		if(ri[mid]>x){
			ret = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	return ret;
}
ll f(ll l,ll r,char ch){
	ll tl = find_left(l);
	ll tr = find_right(r);
	ll ret = 0;
	for(int i=tl;i<=tr;i++){
		cout<<i<<endl;
		if(c[i]!=ch){
			ret = ret + min(ri[i],r) - max(lf[i],l) + 1;
		}
	}
	cout<<endl;
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int rear = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			rear++;
			str[rear] = c[i];
		}
	}
	int cnt = 0,mid = ceil(rear*1.0 / 2);
	for(int i=mid;i<=rear;i++){
		int p = rear - i + 1;
		if(str[p] != str[i]){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
