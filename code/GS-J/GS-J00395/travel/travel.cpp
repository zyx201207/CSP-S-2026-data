#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2, tmp1,tmp2;
char tmp3,tmp4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		tmp1=s1[0]+s1[1],tmp2=s2[0]+s2[1];
		if(tmp1==tmp2){
			cout<<'1';
			tmp3=s1[2],tmp4=s2[2];
			
			if(((tmp3>='A'&&tmp3<='C')&&(tmp4>='A'&&tmp4<='C'))||((tmp3>='D'&&tmp3<='F')&&(tmp4>='D'&&tmp4<='F'))){
				cout<<'1';
				tmp4=s1[2],tmp3=s2[2];
				if(abs(tmp3-tmp4)==1){
					cout<<'1';
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
} 
