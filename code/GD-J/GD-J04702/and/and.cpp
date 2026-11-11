#include <bits/stdc++.h>
using namespace std;
int a[0],b[0];
int mn[0];
int nm[0];
int m,cnt;
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin >> n >> m ;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
	for (int i=0;i<m;i++){
		while(a[i]==0){
			mn[i]=a[i]%2;
			a[i]=a[i]/2;
		}
	}
	for (int i=0;i<m;i++){
		if(mn[i]<mn[i+1]){
			cnt=b[i];
		}
	}
	cout << cnt;
	return 0;
}
