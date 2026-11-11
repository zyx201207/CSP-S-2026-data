#include<bits/stdc++.h>
using namespace std;
int n , mx = 1;
long long m , a[500010] , b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++){
		b[i] = b[i-1]+a[i];
		//cout << b[i] << " ";
	}//cout << endl;
	for(int i = 1; i <= n; i++){
		int l = 1 , r = i , pos = 0;
		while(l <= r){
			int mid = l+(r-l)/2;
			//cout << l <<","<<r << endl;
			if(b[i]-b[mid-1]+m >= a[i]*(i-mid+1)){
				pos = mid;
				r = mid-1;
			}else{
				l = mid+1;
			}
		}//cout << i << " " << pos << endl;
		mx = max(mx,i-pos+1);
	}cout << mx;
	return 0;
}

//1 3 7 15 24
//0 1 3 7 8
