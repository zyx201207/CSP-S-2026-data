#include<bits/stdc++.h>
using namespace std;

long long n,m;

struct MMM{
	long long a,b; 
}a[200005];

bool cmp(MMM x,MMM y){
	if(x.b != y.b)return x.b > y.b;
	return x.a > y.a;
}

int kskbl(long long f){
	int o = 0;
	for(int i = 30;i >= 0;i--){
		if(pow(2,i) <= f){
			f -= pow(2,i);
			o++;
		}
	}
	return o;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		a[i].b = kskbl(x);
		a[i].a = x;
	}
	sort(a+1,a+n+1,cmp);
	long long ans = a[1].a,t = 1;
	for(int i = 2;i <= n;i++){
		if(ans & a[i].a != 0){
			ans = ans & a[i].a;
			t++;
			if(t == m){
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
