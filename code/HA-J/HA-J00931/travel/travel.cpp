#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
		if(r2[0]==x2[0]&&r2[1]==x2[1]){
			cout<<1;
			int m=r2[2]-x2[2];
			if(m<3&&m>-3){
				if((r2[2]=='C'&&x2[2]=='D')||(r2[2]=='D'&&x2[2]=='C')){
					cout<<"00";
				}
				else{
					cout<<1;
					if(m==1||m==-1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
	return 0;
}
