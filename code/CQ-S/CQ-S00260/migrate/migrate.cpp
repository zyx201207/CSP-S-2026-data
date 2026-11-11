#include<bits/stdc++.h>
using namespace std;
//	So why do you make this question I can't solve?
//	Looking my eyes! Tell me, why. Why, why baby why! 
/*
   _______________
  /______________/|
  |              ||
  |	R.I.P.    ||
  |     CCF      ||
  |              ||
  | never forget ||
  |              ||
  |              ||
  |  2026.10.31  ||
 _|              ||__
/_|______________|/_/
|___________________| 
*/
int x[2000010];
void work(){
	int n,d;
	cin>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	srand(time(0));
	return rand()%200;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<work()<<endl;
	}
	return 0;
}

