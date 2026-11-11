#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c=1,d=0;
	int a[1000000000008]={0},b[10000000000008]={0};
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<m;j++){
			b[c]=a[j]-a[i];
			c++;
		}
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<m;j++){
			if(b[i]+b[j]<=m){
				d+=a[i]+a[j];
			}
		}
	}
	cout << d;
	return 0;
}
