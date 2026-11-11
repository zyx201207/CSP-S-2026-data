#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[100001];
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout << a[1];
	}
	else if(m==2){
		cout << a[2];
	}
	else{
		cout << a[m];
	}
	return 0;
}
