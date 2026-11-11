#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+5;
ll a[N];
ull n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,ans=1,k=0;
	for(int i=1;i<=n;i++){
		while(m<(a[i]-a[i-1])*1ULL*k){
			k--;
			m+=a[i-1]-a[l];
			l++;
		}
		m-=(a[i]-a[i-1])*1ULL*k;
		k++;
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}