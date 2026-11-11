#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll m;
ll n;
ll a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll ans=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
	for(int i=1;i<n;i++){
		b[i]=abs(a[i]-a[i+1]);
	} 
	sort(b+1,b+n);
	int k=1,sum=0;
	while(sum+b[k]<=m&&k<=n-1){
	    ans++;
		sum+=b[k];
		k++;
	}
	cout<<ans<<endl;
	return 0;
} 
