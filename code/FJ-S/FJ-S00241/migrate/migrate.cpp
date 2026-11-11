#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1000005]={0},ans=0,cnt=0;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> d;
		for(int j=1;j<=n;j++){
			cin >> x[j];
		} 
		if(n<=2){
			cout << 0 << endl;
		}else{
			for(int k=1;k<=n;k++){
				for(int p=k;p<=n;p++){
					if((x[k]-x[p])>d && k-p==1){
						cout << 0 << endl;
						break;
					}else if(x[k]-x[p]<=d){
						ans++;
					}
				}
				if(ans==2){
					cnt++;
					ans=0;
				}
			}
		}
		cout << cnt << endl;
	} 
	return 0;
}
