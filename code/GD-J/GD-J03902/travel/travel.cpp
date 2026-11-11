#include<bits/stdc++.h> 
using namespace std;
string r_t,x_t,r,x;
bool ra,xa;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r_t>>r;
	if(r[2]=='A'||r[2]=='B'||r[2]=='C')ra=true;
	else ra=false;
	cin>>x_t>>x;
	if(x[2]=='A'||x[2]=='B'||x[2]=='C')xa=true;
	else xa=false;
	if(r_t!=x_t)cout<<"0000";
	else{
		if(r[0]!=x[0]||r[1]!=x[1])cout<<"1000";
		else{
			if(ra!=xa)cout<<"1100";
			else{
				if(r[2]-1==x[2]||r[2]+1==x[2])cout<<"1111";
				else cout<<"1110";
			}
		}
	}
}
