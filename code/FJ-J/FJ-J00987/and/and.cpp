#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],max=0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int maxn;
	for(int i=1;i<=m;i++){
		for(int i=0;i<n;i++){
			if(a[i]>a[i-1]){
				max=a[i];
			}
			if(a[i]>a[i-1]&&a[i]<max){
				maxn=a[i];
			}
		}
	}
	cout << maxn;
	return 0;
}
