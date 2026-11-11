#include<bits/stdc++.h>
using namespace std;

using ll=long long;

const int N=2e5+5;
int n,a[N];
ll ans=0;
char c[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	
	for(int i=1,j=n;i<j;){
		if(a[i]<=a[j]){
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			a[j]-=a[i];
			++i;
		}else{
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			a[i]-=a[j];
			--j; 
		}
	}
	
	cout<<ans<<'\n';
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	while(t--) solve();

	return 0;
}
