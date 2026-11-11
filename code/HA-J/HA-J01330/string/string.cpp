#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt;
char b;
string hwc,h1,h2;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int zj = 0;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		for(int j=0;j<a;j++){
			hwc[zj] = b;
			zj++;
		}
	}
	for(int i=0;i<zj/2;i++) h1[i] = hwc[i];
	for(int i=zj/2;i<zj;i++) h2[i-zj/2] = hwc[i];
	for(int i=0;i<zj/2;i++){
		if(h1[i]!=h2[i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
