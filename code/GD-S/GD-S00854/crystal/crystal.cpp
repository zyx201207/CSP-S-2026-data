#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 5e5+5;

int n;
ll m;
ll a[N];
int ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	sort(a+1,a+n+1);
	int r=0;
	ll res=0;
	for(int i=1;i<=n;i++) {
		res-=a[r]-a[i-1];
		while(r<n) {
			++r;
			ll p=res+(r-i)*(r==i ? 0 : (a[r]-a[r-1]));
			if(p>m || p<0) {
				--r;
				break;
			}
			res=p;
		}
//		cout<<res<<"\n";
		ans=max(ans,r-i+1);
	}
	
	cout<<ans;
	return 0;
} 
