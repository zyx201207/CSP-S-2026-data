#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a1,b1,a2,b2;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>a1>>b1>>a2>>b2;
	x=b1[b1.size()-1];
	b1.erase(b1.size()-1,1);
	y=b2[b2.size()-1];
	b2.erase(b2.size()-1,1);
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		if(b1!=b2){
			cout<<"000";
			return 0;
		}else{
			cout<<"1";
			if((x<='C'&&y>'C')||(x>'C'&&y<='C')){
				cout<<"00";
				return 0;
			}else{
				cout<<"1";
				if((x=='A'&&y=='C')||(x=='C'&&y=='A')){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}
		}
	}
	return 0;
} 
