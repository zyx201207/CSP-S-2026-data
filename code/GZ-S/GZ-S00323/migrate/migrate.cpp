//GZ-S00323 贵阳市第十九中学 唐靖越 
#include<bits/stdc++.h>
using namespace std;
long long n,m,s,ans,c,t,d;
long long a[15000000],x[20000000]; 
bool f=true,ff=true;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1 ; i <= n ; i++){
			cin>>x[i];
		}
		if(x[n]-x[1]<=d){
			cout<<0;
			return 0 ;
		}
		for(int i = 1 ; i <= n  ;i++){
			for(int j = i+4 ; j <= n  ;j++){
				int aa=x[j]-x[i];
				if(aa%d==1){
					f=true;
					ff=true;
					for(int k = i ; k <= j ;k++){
						if(x[k]==x[j]-d-d){
							f=false;
						}
						if(x[k]==x[j]-d&&f==false){
							ff=false;
							continue;
						}
					}
					
				}
				else{
					continue;
				}
				if(ff==true){
					ans++;	
				}	
			}
		}
	}
	cout<<ans;
	return 0 ;
} 

