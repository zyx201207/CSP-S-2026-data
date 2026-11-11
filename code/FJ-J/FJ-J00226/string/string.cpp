#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue
#define st stack
#define qu queue
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define N 200005
char str[N]={0};
ll n=0;
int main(){
	qwq;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll c=0;
	for(ll i=1;i<=n;i++){
		ll a=0;
		char b=0;
		cin>>a>>b;
		for(ll j=c+1;j<=c+a;j++){
			str[j]=b;
		}
		c+=a;
	}
	ll ans=0;
	ll i=1,j=c;
	while(i<j){
		if(str[i]!=str[j]){
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans<<endl;
	return 0;
}
