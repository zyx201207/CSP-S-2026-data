#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,cnt,z=1;
const int N = 2e5+5;
ll a[N];
bool cmp(ll x,ll y){
	return x > y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	cnt = a[1];
	for(int i=1;i<n;i++){
		z++;
		if(cnt & a[i+1] == 0){
			continue;
			z--;
		}
		cnt = cnt & a[i+1];
		if(z == m) break;
		
	}
	cout << cnt;
	return 0;
}
