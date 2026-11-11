#include<bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr[0]==cx[0]&&cr[1]==cx[1]){
		cout<<1;
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			cout<<1;
			if((sr[2]!='C'||sx[2]!='D')&&(sx[2]!='C'||sr[2]!='D')){
				cout<<1;
				if(sr[2] - sx[2]==1||sx[2]-sr[2]==1) cout<<1;
				else {
					cout<<"0";
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}

