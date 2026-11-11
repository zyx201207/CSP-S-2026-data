#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10000001],z=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=i+1;j<=m-1;j++){
			if(s>z){
				z=s;
			}
		}
	}
	cout << z;
	return 0;
}
