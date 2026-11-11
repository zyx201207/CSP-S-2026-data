#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	int num = a[1];
	for(int i=2;i<=m;i++){
		num&=a[i];
	}
	cout << num;
	return 0;
}
