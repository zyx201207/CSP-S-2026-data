#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,p1,p2;
char a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout <<"0000";
		return 0;
	}else{
		cout <<1;
		p1=s1[0]+s1[1];
		p2=s2[0]+s2[1];
		if(p1!=p2){
			cout <<"000";
		}else{
			cout <<1;
			a1=s1[2];
			a2=s2[2];
			if(((a1=='A'||a1=='B'||a1=='C')&&(a2=='D'||a2=='F'))||((a1=='D'||a1=='F')&&(a2=='A'||a2=='B'||a2=='C'))){
				cout <<"00";
			}else{
				cout <<1;
				if(abs(a1-a2)==1)cout <<1;
				else cout <<0;
			}
		}
	}
	return 0;
}
