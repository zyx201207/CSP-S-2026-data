#include<bits/stdc++.h>
using namespace std;
int s1,s2,c1,c2;
char S1[5],S2[5];
bool F(){
	if(S1[2]=='A' || S1[2]=='B' || S1[2]=='C'){
		if(S2[2]=='A' || S2[2]=='B' || S2[2]=='C') return true;
	}
	else if(S1[2]=='D' || S1[2]=='F'){
		if(S2[2]=='D' || S2[2]=='F') return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>S1>>c2>>S2;
	s1=(int)(S1[0])+(int)(S1[1]);
	s2=(int)(S2[0])+(int)(S2[1]);
	if(c1==c2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if(F()){
				cout<<"1";
				if(abs(S1[2]-S2[2])==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
    }
    else cout<<"0000";
	return 0;
}
