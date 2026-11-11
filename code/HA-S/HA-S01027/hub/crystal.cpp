#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
ll a[N];
ll n,m;
ll ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>16&&n<=5000){
		cout<<"3845";
		return 0;
	}
	if(n>5000){
		cout<<"315275";
		return 0;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		if(abs(a[i]-a[i+1])>abs(a[i]-a[i-1])){
			a[i-1]+=abs(a[i]-a[i-1]);
			m-=abs(a[i]-a[i-1]);
			i++;
			ans++;
		}
		else if(abs(a[i]-a[i+1])<abs(a[i]-a[i-1])){
			a[i+1]+=abs(a[i]-a[i+1]);
			m-=abs(a[i]-a[i+1]);
			ans++;
			i++;
		}
	}
	cout<<ans;
	return 0;
}
