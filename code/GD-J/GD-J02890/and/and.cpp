#include <bits/stdc++.h>
using namespace std;
int a[500005],t[500005];
int n,m,b = -1;
//int for_funt(int y,int x){
//	if(y > 0){
//	for (int j = 0;j < n;j++){
//		y-=1;
//		t[y - x] = a[j];
//		for_funt(y,x);
//	}}	
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++) cin >> a[i];
	//for_funt(m,m);
	for (int k = 0;k < n;k++) for (int l = k + 1;l < n;l++) if (a[k] & a[l] > b) b = a[k] & a[l];
	cout << b;
	return 0;}
