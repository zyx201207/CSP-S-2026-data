#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[i] < a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	int x = a[0];
	for(int i=1;i<m;i++){
		x = x & a[i];
	}
	cout << x;
	return 0;
}
