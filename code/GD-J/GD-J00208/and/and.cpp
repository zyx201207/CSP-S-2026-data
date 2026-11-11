#include <bits/stdc++.h>
using namespace std;


int a[200005],mx=-1;
bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		int b[m+5];
		for(int j=1;j<=m;j++){
			b[j]=a[j];
		}
		for(int j=2;j<=m;j++){
			b[i]&=b[i-1];
		}
		mx=max(mx,b[m]);
	}
	cout << mx;
	
	return 0;
}
