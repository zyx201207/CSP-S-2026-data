#include<bits/stdc++.h>
#define ci const int
#define ll long long int
using namespace std;
ci cnt=2e5+2;
ll a[cnt];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll n,m,flag=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==1){
			flag++;
		}
	}
	if(flag==n-1){
		cout << n-m;
	}else{
		cout << a[n-m+1]; 
	}
} 
