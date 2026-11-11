#include<bits/stdc++.h>
using namespace std;
long long n,m,a[3000000],t,x=1,y=2,sumx,sumy;
long long ri=0;
bool v1=0,v2=0,v=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	int z=n;
	cin>>m;
	if(m==1){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<n;
	}
	else{
		
		for(int i=0;i<n;i++){
			cin>>a[i];	
		}
		while(z--){
			for(int i=n-z;i<n;i++){
				if(a[i]==1 and v1){
					ri=1;
					v=0;
					v2=0;
				}
				else if(a[i]==2 and v2){
					ri=1;
					v=1;
					v1=0;
				}
				else if(a[i]==1){
					v1=1;
					ri++;
				}
				else{
					v2=1;
					ri++;
					v=1;
				}
			}
			if(ri>1){
				sumx++;
				sumy++;
			}
			else if(v){
				sumy++;
			}
			else{
				sumx++;
			}
		}
		cout<<sumx<<' '<<sumy; 
	}
	
	return 0;
}
