#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll a[N],b[N],n,m,sum; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a+1,a+n+1);ll l = 1,r = 0,num = 0;
	for(int i = 1 ; i <= n ; i++){
		b[++r] = a[i];num += a[i];
		while(r>=l&&b[r]*(r-l+1) - num > m){
			num -= b[l++];
		}sum = max(sum,r-l+1);
	}cout << sum; 
	return 0;
} 
