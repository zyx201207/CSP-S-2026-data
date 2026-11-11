#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		if(s1.substr(0,2)!=s2.substr(0,2)) cout<<"1000";
		else{
			x=s1.substr(2,1),y=s2.substr(2,1);
			if(!( (y>="A"&&y<="C"&&x>="A"&&x<="C")||(y>="D"&&y<="E"&&x>="D"&&x<="E") ))cout<<"1100";
			else{
				if((x=="B"&&(y=="C"||y=="A")) || (y=="B"&&(x=="C"||x=="A")) || (x=="D"&&y=="E") || (y=="D"&&x=="E")) cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
} 
