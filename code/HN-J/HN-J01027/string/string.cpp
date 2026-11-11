#include<bits/stdc++.h>
using namespace std;
const int N =1e9+3;
typedef long long ll;
char a[N];
ll ans=0;
ll len=0;
ll sum=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(ll j=sum;j<sum+x;j++){
			a[j]=y;
		}
		sum+=x;
	}
	sum-=1;
	ll cnt=sum;
	//for(ll i=1;i<=sum;i++) cout<<a[i];
	for(ll i=1;i<=sum;i++){
		if(i>=cnt) break;
		if(a[i]!=a[cnt]){
			ans++;
		//cout<<i<<" "<<cnt<<"\n";
		}
		cnt-=1;
	}
	cout<<ans;
}
