#include <bits/stdc++.h>
using namespace std;

string cx_r,cx_x,zw_r,zw_x;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx_r>>zw_r>>cx_x>>zw_x;
	if(cx_r!=cx_x){//≥µœ· 
		cout<<"0000";
	}else{
		if(zw_r[0]!=zw_x[0]||zw_r[1]!=zw_x[1]){//≈≈ 
			cout<<"1000";
		}else{
			if(zw_r[2]<='C'&&zw_x[2]<='C'){//±ﬂ 
				if(abs(zw_r[2]-zw_x[2])==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
			
		}
	}
	return 0;
} 
