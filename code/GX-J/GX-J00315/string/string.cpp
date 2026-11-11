#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
#define ll long long
ll n;
char a[N];
ll front,L = 1,R,mid,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		ll x;
		char y;
		cin>>x>>y;
		for(int j = 1;j<=x;j++) a[front+j] = y;
		front += x;
	}
	ll mid = (L+front)/2;
	for(int i = 1;i<=mid;i++){
		if(a[i] != a[front - i + 1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
