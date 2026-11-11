#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s11,s12,s13,s21,s22,s23;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s11>>s12>>s13>>c2>>s21>>s22>>s23;
	if(c1==c2){
		cout<<1;
		if(s11==s21 and s12==s22){
			cout<<1;
			if(abs(s13-s23)<=2){
				if(s13!='C'and s23!='D'){
					if(s13!='D' and s23 !='C'){
						cout<<1;
					
				if(abs(s13-s23==1)){
					if(s13!='C' and s23!='D') {
						if(s13!='D' and s23 !='C'){
							cout<<1;
						}else cout<<0;
					}else cout<<0;
				}else cout<<0;
				}else cout<<0<<0;
				}else cout<<0<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0; 
	}else cout<<0<<0<<0<<0; 
	return 0;
}//代码长得很像比萨斜塔 
