#include<bits/stdc++.h>
using namespace std;
string c1,h1,c2,h2;
int a[10];
int main(){
	
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>h1>>c2>>h2;
	if(c1==c2){
		a[1]=1;
		if(h1[0]==h2[0] && h1[1]==h2[1]){
			a[2]=1;
			if((h1[2]<='C' && h2[2]<='C')||(h1[2]>'C' && h2[2]>'C')){
				a[3]=1;
				if(int(h1[2])-int(h2[2])==1 || int(h2[2])-int(h1[2])==1){
					a[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	
	return 0;
}
