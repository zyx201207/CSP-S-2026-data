#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,n;
	cin >> a >> n;
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[j];
			if(a[i]+a[j]==0){
				cout << -1 << endl;			
			}
		}
	}
	return 0;
}
