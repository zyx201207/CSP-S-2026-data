#include<bits/stdc++.h>
using namespace std;
int a,b;
string as,bs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>as>>b>>bs;
	if(a==b){
		if(as[0]==bs[0]&&as[1]==bs[1]){
			if(as[2]=='A'){
				if(bs[2]=='B')cout<<"1111";
				else if(bs[2]=='C')cout<<"1110";
				else cout<<"1100";
			}else if(as[2]=='C'){
				if(bs[2]=='B')cout<<"1111";
				else if(bs[2]=='A')cout<<"1110";
				else cout<<"1100";
			}else if(as[2]=='B'){
				if(bs[2]=='A')cout<<"1111";
				else if(bs[2]=='C')cout<<"1111";
				else cout<<"1100";
			}else if(as[2]=='D'){
				if(bs[2]=='F')cout<<"1111";
				else cout<<"1100";
			}else  if(as[2]=='F'){
				if(bs[2]=='D')cout<<"1111";
				else cout<<"1100";
			}else cout<<"ERROR";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
