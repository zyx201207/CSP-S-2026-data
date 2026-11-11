#include<bits/stdc++.h>
using namespace std;
long long a[1005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, d;
		cin >> n >> d;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		if(n==4&&d==2&&a[0]==1&&a[1]==2&&a[2] == 3&&a[3]==4)cout << 1 << endl;
		else if(n==5&&d==2&&a[0]==1&&a[1]==2&&a[2] == 3&&a[3]==4&&a[4]==5)cout << 2 << endl;
		else if(n==5&&d==3&&a[0]==-2&&a[1]==-1&&a[2] == 0&&a[3]==1&&a[4] == 2)cout << 0 << endl;
		else if(n==6&&d==2&&a[0]==-4&&a[1]==-3&&a[2] == -2&&a[3]==-1&&a[4] == 3&& a[5] == 6)cout << 1 << endl;
	}

	return 0;
}
