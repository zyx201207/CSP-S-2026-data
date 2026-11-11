#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	char x1,x2,x3,y1,y2,y3;
	cin>>a; cin>>x1>>x2>>x3; cin>>b; cin>>y1>>y2>>y3;
	if(a==b){
		cout<<1;
		if(x1==y1&&x2==y2){
			cout<<1;
			if(x3=='A'||x3=='B'||x3=='C'){
				if(y3=='A'||y3=='B'||y3=='C'){
					cout<<1;
					if(x3=='B'||y3=='B')cout<<1;
					else cout<<0;
					
				}	else cout<<"00";
			}
			else if((x3=='D'&&y3=='F')||(x3=='F'&&y3=='D')){
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
