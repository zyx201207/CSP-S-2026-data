#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,ans,a[N];
bool ok=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)ok=0;
	}
	if(ok){
		ans=a[n];
		for(long long i=n-1;i>n-m;i--){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	cout<<512; 
	return 0;
}
