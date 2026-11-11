#include<bits/stdc++.h>
using namespace std;
string q,z1,z2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>z1>>c2>>z2;
	if(c1==c2){
		q+="1";
		if(z1[0]==z2[0]&&z1[1]==z2[1]){
			q+="1";
			if((z1[2]=='D'||z1[2]=='F')&&(z2[2]=='D'||z2[2]=='F')){
				q+="11";
			}else if((z1[2]=='A'||z1[2]=='B'||z1[2]=='C')&&(z2[2]=='A'||z2[2]=='B'||z2[2]=='C')){
				q+="1";
				if(z1[2]=='A'){
					if(z2[2]=='B'){q+="1";}
					else{q+="0";}
				}else if(z1[2]=='B'){
					if(z2[2]=='A'||z2[2]=='C'){q+="1";}
					else{q+="0";}
				}else if(z1[2]=='C'){
					if(z2[2]=='B'){q+="1";}
					else{q+="0";}
				}
			}else{
				q+="00";
			}
		}else{
			q+="000";
		}
	}else{
		q+="0000";
	}
	cout<<q;
}
