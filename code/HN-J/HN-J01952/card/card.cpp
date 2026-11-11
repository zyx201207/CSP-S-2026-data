#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a+5],d[a+5],f=0;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	
	for(int y=0;y<a;y++){
		d[y]=c[y];
		for(int j=0;j<y;j++){
			if(d[y]==c[j]){
				for(int l=0;l<j;l++){
					d[l]==0;
				}
			}
		}
		for(int h=0;h<b;h++){
		
		    for(int g=0;g<y;g++){
			    if(d[g]==h){
			    	f++;
			    	continue;
				}
		}
		    cout<<f<<" ";
		}
	}
	    

	return 0;
}
