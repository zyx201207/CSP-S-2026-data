#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<1;
		if((sr[0]-'0')*10+sr[1]-'0'==(sx[0]-'0')*10+sx[1]-'0'){
			cout<<1;
			int numr=sr[2]-'A'+1;
			int numx=sx[2]-'A'+1;
			if(numr/4==numx/4){
				cout<<1;
				if(abs(numr-numx)==1)cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
