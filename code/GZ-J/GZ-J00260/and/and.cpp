//贵阳市南明区李端棻中学 刘锦阳 GZ-J00260
#include<bits/stdc++.h>
using namespace std;
bool pos(int a,int b){
	return a > b; 
}
int main(){
	cin.tie(0);cout.tie(0);
	int n,m,a[200001];
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1,pos);
	for(int i = 2;i <= m;i++) a[i] = a[i-1] & a[i];
	cout << a[m];
	return 0;
}
