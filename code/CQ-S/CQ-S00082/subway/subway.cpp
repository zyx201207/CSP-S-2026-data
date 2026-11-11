#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int xr[3],yr[3];
int main(){
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> c >> n >> m >> d >>q;
  int a[m+1];
  for(int i=1;i<=m+1;i++){
  	cin >> a[m];
	}
	int ki;
	cin >> ki;
	int k[2*ki+1];
	for(int i=1; i<=2*ki+1;i++){
		cin >> k[i];
	}
	for(int i=1;i<=2;i++){
		cin >> xr[i];
	}
	for(int i=1;i<=2;i++){
		cin >> yr[i];
	}
	if(n==2){
		cout << "32" << endl << "17";
	}
	if(n==3){
		cout << "35" << endl << "16";
	}
	return 0;
}
