#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[N];
	long long m,cost=0,c1,c2;
	int n;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	c1 = 0;
	for(int i = 2;i <= n;i++){
		c2 = (a[i] - a[i-1])*(i-1) + c1;
		if(c2 > m){
			cout << i-1;
			break;
		}
		c1 = c2;
	}
	return 0;
}
