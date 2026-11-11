#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[105];
	int n ,m ,cnt=2;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=0;i<n;i++){
	for (int j=i+1;j<=m;j++){
		if(a[j]-a[i]==m){
			cnt ++;
			}
		}	
	}
	cout << cnt <<endl;
	return 0;
}
