#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c1,c2,s1,s2;
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(int(s1[0])==int(s2[0])&&int(s1[1])==int(s2[1])){
			cout<<"1";
			if(int(s1[2])==70&&int(s2[2])==68){
				cout<<"11";
			}else if(int(s1[2])==68&&int(s2[2])==70){
				cout<<"11";
			}
			if(int(s1[2])==65||int(s1[2])==66||int(s1[2])==67&&int(s2[2])==65||int(s2[2])==66||int(s2[2])==67){
				cout<<"1";
				if( int(s1[2]) == int(s2[2])-1 || int(s1[2]) == int(s2[2])+1){
					cout<<"1"; 
				}else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

