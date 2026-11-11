#include<bits/stdc++.h>
using namespace std;
long long a[6000];
long long ii;
bool cmp(long long x,long long y){
	return abs(ii - x) < abs(ii - y);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long big = -99999999,small=99999999999;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(big < a[i]){
			big = a[i];
		}
		if(small > a[i]){
			small = a[i];
		}
	}
	long long s = 0;
	for(ii = small;ii <= big;ii++){
		long long num = m;
		long long z = 0;
		sort(a + 1,a + 1 + n,cmp);
		for(int i = 1;i <= n;i++){
			if(num == 0||num < ii - a[i]){
				break;
			}
			if(a[i] == ii){
				z += 1;
			}else if(a[i] < ii&&num >= ii - a[i]){
				z += 1;
				num -= ii - a[i];
			}
		}
		if(z > s){
			s = z;
		}
	}
	cout << s;
	return 0;
}
