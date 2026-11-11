//GZ-S00423 ¿ÓΩ®¿§
#include <bits/stdc++.h>
using namespace std;
const long long int N=1e5;
#define ll long long
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for (int ii=0;ii<t;ii++){
		ll k,l,a[N]={0},num=0;
		cin>>k>>l;
		for (int i=1;i<=k;i++){
			cin>>a[i];
		}
		for (int i=1;i<=k;i++){
			for (int j=3+i;j<k-i;j++){
				ll ok=0;
				if(a[j]-a[i]<=l){
						continue;
					}
				for (int t=i+1;t<j;t++){
					if(a[j]-a[t]<=l&&a[t]-a[i]<=l){
						ok++;
					}
				}
				if (ok==2){
					num++;
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
	

