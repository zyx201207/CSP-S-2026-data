#include<bits/stdc++.h>
using namespace std;
int o[1000001];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
int n,m;
scanf("%d %d",&n,&m);
for(int i=1;i<=n;i++){
	scanf("%d",&o[i]);
}
int p=1;
sort(o+1,o+1+n);
for(int i=n;i>1;i--){
	int a=0,l=1;
	for(int j=i-1;j>=1;j--){
		a=a+o[i]-o[j];
		if(a<=m){		
			l++;			
			}else{			
		break;					
					}						
		}		
		if(l>p){		
			p=l;		
		}			
		if(p==n){break;}		
}		
printf("%d",p); 		
fclose(stdin);	
fclose(stdout);				
}									
