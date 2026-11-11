#include<bits/stdc++.h> 
using namespace std;
struct p{
	string a;
	string b;
	
};
string ans;
p x,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out ","w",stdout);
	cin>>x.a>>x.b>>r.a>>r.b;
	if(x.a[0]==r.a[0]&&x.a[1]==r.a[1]){
		if(x.b[0]==r.b[0]&&x.b[1]==r.b[1]){
			if(char(x.b[2])<='C'&&char(r.b[2])<='C'||char(x.b[2])>='D'&&char(r.b[2])<='D'){
				if(abs(char(x.b[2])-char(r.b[2]))==1){
					cout<<"1111";
				}
				else{
					cout<<"1110" ;
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}	
	else{
		cout<<"0000";
	}
	
	return 0;
}
