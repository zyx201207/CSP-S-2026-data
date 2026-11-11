#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,s;
	cin>>a>>b>>c>>d;
	if(a==c){
		s+="1";
		if(b[1]==d[1]){
			s+="1";
			if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
				s+="1";
				if(abs(int(b[2]-d[2]))==1&&(b[2]!='c'&&d[2]!='d'||d[2]!='c'&&b[2]!='d')) s+="1";
				else s+="0";
			}
			else s+="00";
		}
		else s+="000";
	}
	else s+="0000";
	cout<<s;
	return 0;
}

