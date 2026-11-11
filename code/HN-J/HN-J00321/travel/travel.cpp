#include<bits/stdc++.h>//Trick||Treat!
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rx,ry,xx,xy;
	cin>>rx>>ry>>xx>>xy;
	if(rx!=xx){
		cout<<"0000";
	}else{
		cout<<1;
		if(ry[0]!=xy[0] or ry[1]!=xy[1]){
			cout<<"000";
		}else{
			cout<<1;
			if((ry[2]<='C' and ry[2]>='A'and xy[2]<='F' and xy[2]>='D') or(xy[2]<='C' and xy[2]>='A'and ry[2]<='F' and ry[2]>='D')){
				cout<<"00";	
			}else{
				cout<<1;
				if((ry[2]=='D')or(xy[2]=='D')or(ry[2]+1==xy[2])or(xy[2]+1==ry[2])){
					cout<<1;
				}else{
					cout<<"0";
				}
			}
		}
	}
	return 0;
} 
