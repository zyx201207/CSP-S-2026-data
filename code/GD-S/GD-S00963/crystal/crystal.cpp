#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=1;
	int ans=1;
	while(r<n&&l<=n&&l<=r){
		r++;
		if(1ull*(r-l)*(a[r]-a[r-1])>m){
			while(1ull*(r-l)*(a[r]-a[r-1])>m){
				m+=(a[r-1]-a[l]);
				l++;
			}
			m-=1ull*(r-l)*(a[r]-a[r-1]);
		}
		else{
			m-=1ull*(r-l)*(a[r]-a[r-1]);
		}
		if(l>r||r>n||l>n)break;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}

