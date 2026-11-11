#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string e="",f="";
	char x,y;
	int m=0,n=0;
	if(a!=c){
		cout<<"0000";
	}
	else{
		for(int i=0;i<2;i++){
			e+=b[i];
			f+=d[i];
		}
		if(e!=f){
			cout<<"1000";
		}
		else{
			x=b[2];
			y=d[2];
			if('A'<=x && x<='C' && (y=='D'|| y=='F')){
				cout<<"1100";
			}
			else if(x=='D'|| x=='F' && ('A'<=y && y<='C')){
				cout<<"1100";
			}
			else{
		    	if(int(x)+1!=int(y)){
		    	    cout<<"1110";
				}
				else{
					cout<<"1111";
				}
			}
		}
	}		
	return 0;
}
