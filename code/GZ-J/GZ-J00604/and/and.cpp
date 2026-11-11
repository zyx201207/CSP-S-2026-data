//GZ-J00604 遵义市新蒲中学 杨子曦
#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,o = INT_MIN,p;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		o = max(o,a[i]);
	}
	if(m == 1){
		cout << o;
		return 0;
	}
	if(m == 2){
		o = INT_MIN;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				o = max(o,a[i]&a[j]);
			}
		}
		cout << o;
		return 0;
	}
	if(m == n){
		o = INT_MIN;
		for(int j = 2;j <= n;j++){
			a[1] = a[1] & a[j];
		}
		cout << a[1];
		return 0;
	}
	if(m == n-1){
		o = INT_MIN;
		long long t;
		for(int i = 1;i <= n;i++){
			if(i == 1){
				t=a[2];
				p=2;
			}else{
				t = a[1];
				p = 1;
			}
			for(int j = 1;j <= n;j++){
				if(j == p||j == i){
					continue;
				}
				t = t & a[j];
			}
			o = max(t,o);
		}
		cout << o;
		return 0;
	}
	return 0;
}  
