#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10;
int n,a[N],m,l = 0,r,s[N],su[N];

int qz(int x,int y){
	return s[y]-(x-1)*a[y]+su[x-1];
}

bool check(int mid){
	for(int i = mid;i <= n;i++){
		int x = i-mid+1,y = i;
		int cn = 0;
		int ans = qz(x,y-cn);
		if(x == y){
			ans = 0;
		}
		if(x ==1){
			ans = s[y];
		}
		if(ans <= m){
			return true; 
		}
	}
	return false;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	r = n+1;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	s[1] = 0,s[2] = a[2]-a[1];
	for(int i = 3;i <= n;i++){
		s[i] = (a[i]-a[i-1])*(i-1)+s[i-1];
	}
	for(int i = 1;i <= n;i++){
		su[i] = a[i]+su[i-1];
	}
	while(l+1 < r){
		int mid = (l+r)/2;
		if(check(mid)){
			l = mid;
		}else{
			r = mid;
		}
	}
	cout << l;
	return 0;
}


