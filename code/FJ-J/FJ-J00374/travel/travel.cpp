#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	string x,xq,s,sq;
	cin>>x>>xq>>s>>sq;
	if(x==s){
		cout<<1;
		if(xq[0]==sq[0] && xq[1]==sq[1]){
			cout<<1;
			int a=xq[2]-'A';
			int b=sq[2]-'A';
			if((a>=0 && a<=2 && b>=0 && b<=2) || (a>=3 && a<=4 && b>=3 && b<=4) ){
				cout<<1;
				if(abs(a-b)<=1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
} 
