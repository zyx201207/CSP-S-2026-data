#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
int p1,p2,z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		p1=(s1[0]-'0')*10+(s1[1]-'0'),p2=(s2[0]-'0')*10+(s2[1]-'0');
		if(p1==p2){
			bool flag=0;
			z1=s1[2],z2=s2[2];
			if(z1<='C'&&z2<='C')flag=1;
			else if(z1>'C'&&z2>'C') flag=1;
			if(flag){
				flag=0;
				if(z1=='A') if(z2=='B') flag=1;
				else if(z1=='B') if(z2=='A'||z2=='C') flag=1;
				else if(z1=='C') if(z2=='B') flag=1;
				else if(z1=='D') if(z2=='F') flag=1;
				else if(z1=='F') if(z2=='D') flag=1;
				if(flag) cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";	
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	
	return 0;
}

