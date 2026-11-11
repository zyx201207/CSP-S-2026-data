#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,e="";
int main(){
	//×¢Òâ£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
	 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>a>>b>>c>>d;
	if (a==c){
		e="1";
		if (b[0]==d[0] and b[1]==d[1]){
			e="11";
			if ((('A'<=b[2] and b[2] <='C') and ('A'<=d[2] and d[2] <='C')) or (('D'<=b[2] and b[2] <='E') and ('D'<=d[2] and d[2] <='E')) ){
				e="111";
				if (abs(b[2]-d[2])==1){
					e="1111";
				}else{
					e="1110";
				}
			}else{
				e="1100";
			}
		}else{
			e="1000";
		}
	}else{
		e="0000";
	}
	cout<<e;
	return 0;
}
