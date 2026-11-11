#include<bits/stdc++.h>
using namespace std;
string c2,c4,cc="";
long long c1,c3,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cc+='1';
	}else{
		cout<<"0000";
		return 0;
	}a=(c2[0]-'0'*10)+(c2[1]-'0');
	b=(c4[0]-'0'*10)+(c4[1]-'0');
	if(a==b){
		cc+='1';
		if(c2[2]>='A'&&c2[2]<='C'&&c4[2]>='A'&&c4[2]<='C'){
			cc+='1';
		}else if((c2[2]=='D'||c2[2]=='F')&&(c4[2]=='D'&&c4[2]=='F')){
			cc+='1';
		}else{
			cc+='0';
		}
	}else{
		cc+='0';
		cc+='0';
	}if(abs(b-a)==1&&c2[2]==c4[2]){
		cc+='1';
		cout<<cc;
		return 0;
	}else{
		if((c2[2]=='D'||c2[2]=='F')&&(c4[2]=='D'||c4[2]=='F')){
			if(a==b&&((c2[2]=='D'&&c4[2]=='F')||(c2[2]=='F'&&c4[2]=='D'))){
				cc+='1';
			}else{
				cc+='0';
			}cout<<cc;
			return 0;
		}else{
			if(c2[2]=='D'||c2[2]=='F'||c4[2]=='D'||c4[2]=='F'){
				cc+='0';
				cout<<cc;
				return 0;
			}else{
				if(abs(c2[2]-c4[2])==1&&a==b){
					cc+='1';
					cout<<cc;
					return 0;
				}else{
					cc+='0';
					cout<<cc;
					return 0;
				}
			}
		}
	}
	return 0;
}
