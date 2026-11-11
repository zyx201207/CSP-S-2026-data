//石阡县文博中学 刘贝宁 GZ-S00353 
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5){
		if(n==1){
			cout << 1;
		}
		if(n==2){
			if(a[2]-a[1]<=m){
				cout << 2;
			}
			else{
				cout << 1;
			}
		}
		if(n==3){
			if((a[3]-a[2])+(a[3]-a[1])<=m){
				cout << 3;
			}
			else if(a[3]-a[2]<=m||a[3]-a[1]<=m){
				cout << 2;
			}
			else{
				cout << 1;
			}
		}
		if(n==4){
			if((a[4]-a[3])+(a[4]-a[2])+(a[4]-a[1])<=m){
				cout << 4;
			}
			else if(((a[3]-a[2])+(a[3]-a[1])<=m)||((a[4]-a[3])+(a[4]-a[2])<=m)){
				cout << 3;
			}
			else if(a[4]-a[3]<=m||a[3]-a[2]<=m||a[2]-a[1]<=m){
				cout << 2;
			}
			else{
				cout << 1;
			}
		}
		if(n==5){
			if((a[5]-a[4])+(a[5]-a[3])+(a[5]-a[2])+(a[5]-a[1])<=m){
				cout << 5;
			}
			if(((a[4]-a[3])+(a[4]-a[2])+(a[4]-a[1])<=m)||((a[5]-a[4])+(a[5]-a[3])+(a[5]-a[2])<=m)){
				cout << 4;
			}
			else if(((a[3]-a[2])+(a[3]-a[1])<=m)||((a[4]-a[3])+(a[4]-a[2])<=m)||((a[5]-a[4])+(a[5]-a[3])<=m)){
				cout << 3;
			}
			else if(a[4]-a[3]<=m||a[3]-a[2]<=m||a[2]-a[1]<=m||a[5]-a[4]<=m){
				cout << 2;
			}
			else{
				cout << 1;
			}
		}
	}
	else{
		int zh=1;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]==a[i-1]-a[i-2]){
				zh=1;
			}
			else{
				zh=0;
			}
		}
		if(zh=1){
			cout << m/(a[2]-a[1])+1;
		}
	}
	return 0;
}
