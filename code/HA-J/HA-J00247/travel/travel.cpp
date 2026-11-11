#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string x1 = s1.substr(0,2),x2 = s2.substr(0,2);
	char y1 = s1[2],y2 = s2[2];
	if(c1==c2){
	    cout<<"1";
	    if(x1==x2){
	    	cout<<"1";
	    	if(y1=='A'||y1=='B'||y1=='C'){
	    		if(y2=='A'||y2=='B'||y2=='C'){
	    			cout<<"1";
	    			if(y1-y2==1||y2-y1==1){
	    				cout<<"1";
	    				return 0;
					}
					else{
						cout<<"0";
						return 0;
					}
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else if(y1=='D'||y1=='F'){
				if(y2=='D'||y2=='F'){
					cout<<"11";
					return 0;
				}
				else{
					cout<<"00";
					return 0;
				}
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else cout<<"0000";
	return 0;
}
