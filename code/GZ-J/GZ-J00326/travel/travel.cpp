//GZ-J00326 遵义市第19中学 方睿航 
#include <bits/stdc++.h>
using namespace std;
int rxiang,xxiang,a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    
    string r,x;
	cin>> rxiang>>r>>xxiang>>x;
	if(rxiang==xxiang){
		a=1;
		if(r[0]==x[0] && r[1]==x[1]){
			b=1;
			if((r[2]<='C' && x[2]<='C') || (r[2]>'C' && x[2]>'C')){
				c=1;
				if(abs(int(r[2])-int(x[2]))==1){
					if((r[2]=='C' && x[2]=='D') || (r[2]=='D' && x[2]=='C')){
						d=0;
					}else{
						d=1;
					}
				}else{
					d=0;
				}
			}else{
				c=0;
			}
		}else{
			b=0;
		}
	}else{
		a=0;
	}
	cout<<a<<b<<c<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

