#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,a1="",b1="";
	char c1,d1;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		a1+=b[0]+b[1];
		b1+=d[0]+d[1];
		if(a1==b1){
			cout<<"1";
			if(b[2]<='C'&&d[2]<='C'){
				cout<<"1";
				c1=max(b[2],d[2]);
				d1=min(b[2],d[2]);
				if(c1-1==d1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(b[2]>='D'&&d[2]>='D')
			{
				cout<<"11";
				
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
