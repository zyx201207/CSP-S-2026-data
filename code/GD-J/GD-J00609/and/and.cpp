#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],sum,sum1,x,l;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+0,a+n,cmp);
		cout<<a[0];
		return 0;
	}if(m==n){
		sum=a[0]&a[1];
		for(ll i=2;i<n-1;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	if(m==n-1){
		sum=a[0];
		for(ll i=1;i<m;i++){
			sum=sum&a[i];
		}for(ll i=1;i< n;i++){
			sum1=sum1&a[i];
		}
		cout<<max(sum,sum1);
		return 0;
	}if(m==2){
		x=a[0];
		for(ll i=1+l;i<n;i++){
			x=max(x&a[i+1],a[i]&a[i+1]);
			l++;
		}
		cout<<x;
		return 0;
	}
	cout<<0;
}
