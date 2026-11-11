#include<bits/stdc++.h>
#define ll long long
using namespace std;

string x1,x2;
string y,y2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>x1>>y>>x2>>y2;
	
	if(x1!=x2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		ll q=y[0]*10+y[1],w=y2[0]*10+y2[1];
		char a=y[2],b=y2[2];
		
		if(q==w){
			cout<<"1";
			
			if((a<='C' && b<='C') || (a>='D' && b>='D')){
				cout<<"1";
				if(a+1==b || b+1==a){
					cout<<"1";
				}else{
					cout<<"0";
				}
				
			}else{
				cout<<"00";
			}
			
		}else{
			cout<<"000";
			return 0;
		}
	}
	return 0;
}
