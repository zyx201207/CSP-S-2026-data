#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t = -1;
	cin >> c >> t;
	for(int i=0;i<t;i++){
		int n,d,cnt = 0,x[5005];
		cin >> n >> d;
		for(int j=0;j<n;j++){
			cin >> x[j];
		}
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				for(int a=0;a<n;a++){
					if((k-j)/2+1 == d){
						cnt++;
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

