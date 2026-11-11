#include<iostream>
#include<algorithm>
#include<cmath>
const int N = 2e5+10;
using namespace std;
long long n,m;
long long a[N];
int p,q;
int vit(long long p){
	for(int i = 1;i <= 20;i++){
		if(pow(2,i) > p)return i-1;
		else if(pow(2,i) == p)return i;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin >> n >> m;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	if(m == 1){
		cout << a[n];
		return 0;
	}else if(m == n){
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			ans += a[i];
		}
		int q = vit(ans);
		cout << q;
		return 0;
	}
	cout << 0;
	return 0;
}
