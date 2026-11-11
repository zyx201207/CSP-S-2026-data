#include <bits/stdc++.h>
using namespace std;
int n = 0;
int m = 0;
long long a[1000001] = {};
//long long b[1000001] = {};
bool camp(int a,int b){
	return a > b;
}
int main(){
freopen("and5.in","r",stdin);
freopen("and.ans","w",stdout);
cin >> n >> m;
for(int i = 0;i < n;i++){
	cin >> a[i];
}
//for(int i = 0;i < n-1;i++){
//	for(int j = i;j < i+m-1;j++){
//		b[i] = a[j] & a[j+1];
//	}
//}
sort(a,a+n,camp);
int b = 0;
for(int j = 0;j < m-1;j++){
	b = a[j] & a[j+1];
}
//sort(b,b+n-1);
cout << b;

	return 0;
}

