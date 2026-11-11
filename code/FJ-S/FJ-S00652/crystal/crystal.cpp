#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],l=1,sum,mx,b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		a[i]=a[i+1]-a[i];
		b[i]=a[i]+a[i-1];
		sum+=(i-l+1)*a[i];
		if(sum>m){
			while(l<=i){
				sum-=(b[i]-b[l-1]);
				l++;
				if(sum<=m)break;
			}
		}
		mx=max(mx,i-l+1);
	}
	cout<<mx+1;
	return 0;
} 
