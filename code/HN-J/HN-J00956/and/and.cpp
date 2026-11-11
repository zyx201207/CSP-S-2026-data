#include<bits/stdc++.h>
using namespace std;
const int N=1e5+8;
int a[N];
int t=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
		for(int j=0;j<=m;j++){
			if(a[j]&a[j+1]>t){
				a[j]=a[j]&a[j+1];
				break;
			}
			sort(a,a+n);
			a[1]=a[j];
		}
	}
	cout << a[1];
	return 0;
}
