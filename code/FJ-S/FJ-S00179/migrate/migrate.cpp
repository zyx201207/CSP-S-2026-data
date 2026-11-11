#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,xl[2000010],xr[2000010],f[2000010],an;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>xl[j];		
			xr[j]=xl[j]+d;
		}
		for(int j=1;j<=n;j++){
		    for(int k=1;k<=n;k++){  
		    	if(xr[j]<=xl[k]){
		    		f[j]=xl[k];
				}
				else{
					an++;
					break;
				}
			}
		}
		cout<<0;
	} 
	return 0;
} 
