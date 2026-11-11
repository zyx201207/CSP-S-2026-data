#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+3;
ll a[N];
ll q[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	sort(a+1,a+n+1);
    q[1]=a[1];

	for(int i=2;i<=n;i++){
		q[i]=a[i]+q[i-1];
	}
	int ans=1;
	int r=1;
    for(int l=1;l<=r;l++){
    	while( (r-l+1)*a[r] - (q[r]-q[l-1]) <=m&&r<=n){
    		r++;
		}
		r--;
		int len=r-l+1;
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
