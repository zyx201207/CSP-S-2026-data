#include<bits/stdc++.h>
using namespace std;
int c,t,n,sum=0,ans,a[2000005];
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		cin>>n>>d;
		for(int i=1;i<=d;i++){
			cin>>a[i];
		}
		for(int i=1;i<=d;i++){
			for(int k=1;k<=d;k++){
				if(a[i]%a[k]==1){
					while(ans>2){
						int x=k,ans=4;
						if(a[x]+d==a[i]){
							ans--;
							x++;
						}
					}
					sum++;
				}
			}
		}cout<<sum<<endl;
	}
	return 0;
}
