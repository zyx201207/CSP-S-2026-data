#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500005;
ll n,m;
ll maxn=-1e18;
ll ans[N],a[N];
ll q[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	
	
	for(int i=0;i<n;i++){
	 cin>>a[i];
    } 
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a,a+n);
	for(int i=2;i<n;i++){
		q[i-1]=q[i-2]+a[i-1];
	}
	for(int i=1;i<n;i++){
		int mf=m;
		for(int j=i-1;a[i-1]-a[j]<=mf;j++){
			if(mf>=q[i-1]){
				ans[i-1]=i;
				continue;
			}
			mf=mf-(a[i-1]-a[j]);
			ans[i-1]++;
		}
	}
	for(int i=1;i<n;i++){
		maxn=max(maxn,ans[i-1]);
	}
	
	cout<<maxn;
	cout<<'\n';
	
	return 0;
}
