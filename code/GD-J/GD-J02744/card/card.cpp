#include <bits/stdc++.h>
using namespace std;
int a[2000000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	
	int k=a[0];
	for(int i=1;i<m;i++){
		k=k&a[i];
	}
	cout << k;
	return 0;
}
