#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		k+='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			k+='1';
			if(!((b[2]<='C'&&'C'<d[2])||(d[2]<='C'&&'C'<b[2]))){
				k+='1';
				if(abs(b[2]-d[2])==1)k+='1';
				else k+='0';
			}
			else k+="00";
		}
		else k+="000";
	}
	else k="0000";
	cout<<k; 
	return 0;
} 


