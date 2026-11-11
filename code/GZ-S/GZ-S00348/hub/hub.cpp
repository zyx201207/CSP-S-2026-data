//GZ-S00348¿ÓÍª—Ù 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c = 0,t = 0;
	cin>>c>>t;
	cin.tie(0);
	for(int h = 0;h < t;h++){
		int n = 0,k = 0;
		cin>>n>>k;
		int db1 = 0;
		int db2 = 0;
		int b[10001] = {0};
		cin>>db1>>db2;
		b[0] = db1;
		b[1] = db2;
		int z = 1;
		for(int i = 1;i < n-1;i++){
			int db3 = 0;
			int db4 = 0;
			cin>>db3>>db4;
			if(b[i] == db3){
				b[i+1] = db4;
			}else{
				continue;
			}
		}
		int x = 0;
		for(int i = 0;i < n;i++){
			x = x + b[i];
		}
		if(x == (n-(n-1)+n)*n/2){
			cout<<z;
		}
	}
	return 0;
}
