//石阡县文博中学 刘贝宁 GZ-S00353 
#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		int n,d,cnt=0;
		int x[200005]={0};
		cin >> n >> d;
		for(int j=1;j<=n;j++){
			cin >> x[j];
		}
		if(n==1){
			cout << 0;
		}
		else if(n==2){
			cout << 0;
		}
		else if(n==3){ 
			cout << 0;
		}
		else if(n==4){
			if((x[4]-x[1])>=d) {
				if((x[2]-x[1]<=d&&x[4]-x[2]<=d) ||(x[3]-x[1]<=d&&x[4]-x[3]<=d)) cnt++;
			}
			cout << cnt;
		}
		else if(n==5){
			cnt=0;
			if((x[4]-x[1])>=d) {
				if((x[2]-x[1]<=d&&x[4]-x[2]<=d) ||(x[3]-x[1]<=d&&x[4]-x[3]<=d)) cnt++;
			}
			if((x[5]-x[2])>=d) {
				if((x[3]-x[2]<=d&&x[5]-x[1]<=d) ||(x[4]-x[2]<=d&&x[5]-x[4]<=d)) cnt++;
			}
			cout << cnt;
		}
		int zh=1;
		for(int j=3;j<=n;j++){
			if(x[j]-x[j-1]==x[j-1]-x[j-2]){
				zh=1;
			}
			else{
				zh=0;
			}
		}
		if(zh=1&&x[2]-x[1]<=d){
			cout << (x[n]-x[1])/(d/(x[2]-x[1]));
		}
	}
	return 0;
}
