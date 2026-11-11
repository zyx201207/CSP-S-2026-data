#include<bits/stdc++.h>
using namespace std;
const long long N = 200000 + 7;
pair<long long,char> a[N],cpa,cpb;
long long n,x,ans,l,r;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++) {cin >> x >> c;a[i] = {x,c};}
	l = 1,r = n;
	cpa = a[1];cpb = a[n];
	while(l < r){
		long long L1 = cpa.first,L2 = cpb.first;
		char C1 = cpa.second,C2 = cpb.second;
		//[L1,C1] = cpa;
		//[L2,C2] = cpb;
		//cout << L1 << "," << C1 << ";" << L2 << "," << C2 << endl;
		
		if(C1 != C2) ans += min(L1,L2);
		if(L1 < L2) {cpb = {(L2 - L1),C2};cpa = a[++l];}
		else if(L1 > L2) {cpa = {(L1 - L2),C1};cpb = a[--r];}
		else {cpa = a[++l],cpb = a[--r];}
	}
	cout << ans;
	return 0;
}
