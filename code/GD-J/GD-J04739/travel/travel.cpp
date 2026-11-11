#include<bits/stdc++.h>
using namespace std;
string r,x;
string posr,posx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>posr>>x>>posx;
	if(r[0]==x[0]&&r[1]==x[1]) {
		cout<<"1";
		if(posr[0]==posx[0]&&posr[1]==posx[1]) {
			cout<<"1";
			bool flagr=0,flagx=0;
			
			if(posr[2]=='A'||posr[2]=='B'||posr[2]=='C') flagr=1;
			if(posx[2]=='A'||posx[2]=='B'||posx[2]=='C') flagx=1;
			
			if(flagr==flagx){
				cout<<"1";
				if(abs(int(posr[2]-posx[2]))==1) cout<<"1"<<endl;
				else cout<<"0"<<endl;
				return 0; 
			}
			else {
				cout<<"00"<<endl;
				return 0;
			}
		}
		else {
			cout<<"000"<<endl;
			return 0;
		}
	}
	else{
		cout<<"0000"<<endl;
		return 0;
	}
}

