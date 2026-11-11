#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >>T;
	while(T--){
		int n,d,cha=0;
		cin >> n >> d;
		for(int i = 1;i<=n;i++){
			cin >>a[i];
		}
		cha=a[2]-a[1];
		d/=cha;
		if(d*2>n)cout <<"0\n";
		else{
			cout << n-d*2+1<<"\n";
		}
	}
} 
