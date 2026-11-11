#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		vector<int>x(n+1);
		for(int i=1;i<=n;i++) cin >> x[i];
		int diff=x[2]-x[1];
		if(diff*2<=d&&d<diff*3){
			cout << max(0,n-3) << '\n';
		}else cout << 0; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

