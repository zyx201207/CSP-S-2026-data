//GZ-S00348¿ÓÍª—Ù 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c = 0;
	int t = 0;
	cin>>c>>t;
	for(int h = 0;h < t;h++){
		int n = 0;
		cin>>n;
		int zd = 0;
		cin>>zd;
		int a[10001] = {0};
		for(int i = 0;i < n;i++){
			cin>>a[i];
		}int z = 1;
		for(int i = 0;i < n;i++){
			int js = 0;
			
			for(int j = i+=zd+1;j >= 0;j--){
				if(a[j] - zd > 0){
					js += a[j] - a[j-zd];
				}else if(a[j] - zd == 1){
					js += a[j-zd] - a[0];
				}
			}
			int js1 = 0;
			for(int j = i+=zd+1;j >= 0;j--){
				if(a[j] - 1 == zd){
					js += a[j]-a[j-1];
				}else if(a[j] - zd == 0){
					js += a[j-1] - a[0];
				}
			}
			if(js == js1){
				z++;
			}
		}
		cout<<z<<endl;
	}
	return 0;
}
