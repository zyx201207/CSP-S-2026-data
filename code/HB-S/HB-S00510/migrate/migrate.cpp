#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int i=0;i<t;i++){
		int n,d;
		cin >> n >> d;
		int a[n];
		for(int j=0;j<n;j++){
			cin >> a[j];
		}
		int ans=0;
		for(int x=0;x<n;x++){
			int s=a[x]+d*2;
			for(int y=x+1;y<n;y++){
				if((a[y]-a[x]<=s && a[y]-a[x]>d) && y-x==3) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
