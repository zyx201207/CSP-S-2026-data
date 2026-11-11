#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		int x,y;
		x=b[0]*10+b[1];
		y=d[0]*10+d[1];
		
		if(x!=y){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			int z=b[2]-'A',t=d[2]-'A';
			if(z>=3&&t>=3||z<=2&&t<=2)cout<<"1";
			else{
				cout<<"00";
				return 0;
			}
			if(abs(int(b[2]-d[2]))!=1){
				cout<<"0";
				return 0;
			}
			else cout<<"1";
		}
	}
	return 0;
} 
