#include <bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int f1=0,f2=0,f3=0,f4=0;
	cin>>c1>>c2>>c3>>c4;
	if(c1[1]==c3[1]&&c1[0]==c3[0]) {
		f1=1;
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			f2=1;
			char a=min(c2[2],c4[2]),b=max(c2[2],c4[2]);
			if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
				f3=1;
				if(a=='C'&&b=='D') f4=0;
				else{
					if(b-a==1) f4=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
			
	return 0;
} 
