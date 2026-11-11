#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ll cnt=0,w=m,v=0,j=n;
	for(int i=n;i>=1;i--){
		w+=v*(a[i+1]-a[i]);
		while(j>=1&&w>=a[i]-a[j]){w-=(a[i]-a[j]);j--;}
		cnt=max(cnt,i-j);v=i-j;
	}
	cout<<cnt;
	return 0;
}
