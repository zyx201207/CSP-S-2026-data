//GZ-J00099 ¶Å³¿¼Î 
#include<bits/stdc++.h>
using namespace std;
int rc,xc;
int rh,xh;
string rs,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		cout<<'1';
		for(int i=0;i<2;i++){
			rh=rh*10+int(rs[i]-'0');
			xh=xh*10+int(xs[i]-'0');
		}
		if(rh==xh){
			cout<<'1';
			if((rs[2]<='C'&&xs[2]<='C')||(rs[2]>='D'&&xs[2]>='D')){
				cout<<'1';
				if(rs[2]+1==xs[2]||xs[2]+1==rs[2]){
					cout<<'1';
				}else{
					cout<<'0';
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
