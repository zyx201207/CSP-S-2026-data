#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>c;
	cin>>b>>d;
	if(a!=b){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		if(c[0]!=d[0]||c[1]!=d[1]){
			cout<<"000";
		    return 0;
		}else{
			cout<<"1";
			if(c[2]=='A'||c[2]=='B'||c[2]=='C'){
				if(d[2]!='A'&&d[2]!='B'&&d[2]!='C'){
					cout<<"00";
					return 0;
				}else{
					cout<<"1";
					if(c[2]=='B'||d[2]=='B'){
						cout<<"1";
				    }else{
				    	cout<<"0";
					}
				}
			}else{
				if(d[2]!='E'&&d[2]!='D'){
					cout<<"00";
					return 0;
				}else{
					cout<<"11";
					return 0;
				}
			}
		}
	}
	return 0;
}
