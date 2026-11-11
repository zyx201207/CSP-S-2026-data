#include<bits/stdc++.h>
using namespace std;
bool c(int a,int b){
	return a>b;
}int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}sort(a+1,a+n+1,c);
	int b=a[1];
	for(int i=2;i<=m;i++){
		b&=a[i];
	}cout << b;
	return 0;
} 
