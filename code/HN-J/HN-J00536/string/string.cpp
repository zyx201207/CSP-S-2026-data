#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e8+20;
int n;
int d[N],a[N];
ll len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(ll i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		d[len+1]+=(c-'a'+1);
		d[len+x+1]-=(c-'a'+1);
		len+=x;
	}
	for(ll i=1;i<=len;i++){
		a[i]=a[i-1]+d[i];
	}
//	for(int i=1;i<=len;i++){
//		cout<<a[i];
//	}
	ll ans=0,l=1,r=len;
	while(l<r){
		if(a[l]!=a[r]){
			ans++;
		}
		l++,r--;
	}
	cout<<ans<<endl;
	return 0;
}

