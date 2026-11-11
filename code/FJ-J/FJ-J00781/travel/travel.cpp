#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4,r,x;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
		r=c2[0]+c2[1];
		x=c4[0]+c4[1];
		if(r==x){
			cout<<1;
			if(!((c2[2]=='C' && c4[2]=='D') || (c2[2]=='D' && c4[2]=='C'))){
				cout<<1;
				if(abs(int(c2[2]-c4[2]))==1)
					cout<<1;
				else
					cout<<0;
			}else
				cout<<"00";
		}else
			cout<<"000";
	}else
		cout<<"0000";
	return 0;
}
