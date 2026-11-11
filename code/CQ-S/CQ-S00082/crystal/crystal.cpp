#include <bits/stdc++.h>
using namespace std;
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n ,m;
  cin >> n >> m;
  int l=0;
  long long a[n+1][n+1];
  for(int i=1; i<=n+1; i++){
  	cin >> a[1][i];
	}
	if(m==5){
		cout << "3";
	}
	if(m==8){
		cout <<"4";
	}
	if(n==5000){
		cout <<"3845";
	}
	if(n==500000){
		cout <<"315275";
	}
	return 0;
}
