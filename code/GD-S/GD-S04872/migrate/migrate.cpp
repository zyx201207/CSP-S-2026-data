#include<bits/stdc++.h>
using namespace std;
int main(){
	
	
	freopen("migrate.in","r",stdin);
	long long wy,shuliang,temp=0,shuchu=0;
	
	cin>>wy>>shuliang;
	
	long long dy,juli,dyl[2000001];
	while (shuliang--){
		cin>>dy>>juli;
		for (int i=1;i<=dy;i++){
			cin>>dyl[i];
		}
		
		
		if (dy%juli==0){
		
			for (int k=1;k<=dy/juli-1;k++){//»»+1 
			
				for (int i=juli;i>=1;i--){
					for (int j=juli;j>=1;j--){
						if (i+j+dyl[k]==dyl[dy-k+1]){
							temp++;
						}
					}
					
					if (temp==2){
						shuchu++;
					}
					temp=0;
				}
				
			}
			cout<<shuchu<<endl;
			shuchu=0;
		}
		else{
			for (int k=1;k<=dy/juli-1;k++){//»»+1 
			
				for (int i=juli;i>=1;i--){
					for (int j=juli;j>=1;j--){
						if (i+j+dyl[k]==dyl[dy-k+1]){
							temp++;
						}
					}
					
					if (temp==2){
						shuchu++;
					}
					temp=0;
				}
				
			}
			cout<<shuchu<<endl;
			shuchu=0;
		}
	}
	
	
	
	freopen("migrate.out","w",stdout);
	return 0; 
}
