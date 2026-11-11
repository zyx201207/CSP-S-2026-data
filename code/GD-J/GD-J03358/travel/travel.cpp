#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("trevel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	
	string a,b,c,d;
	cin>>a>>c>>b>>d;

	
	if(a==b){
		cout<<"1";
		if(c[0]==d[0]&&c[1]==d[1]){
			cout<<"1";
			if(!(min(c[2],d[2])<='C'&&max(c[2],d[2])>='D')){
				cout<<"1";
				if(abs(c[2]-d[2])==1||(abs(c[2]-d[2])==2&&(c[2]=='F'||d[2]=='F')))cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	
	

	
	
	return 0;
}
