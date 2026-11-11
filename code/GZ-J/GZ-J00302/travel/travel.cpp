//GZ-J00302 遵义市第四中学 马跃腾 
#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int p1=(s1[0]-'0')*10+s1[1]-'0';
	int p2=(s2[0]-'0')*10+s2[1]-'0';
	if(c1==c2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F'){
				cout<<"11";
			}
			else if(s1[2]=='A'&&s2[2]=='C'||s2[2]=='A'&&s1[2]=='C'){
				cout<<"10";
			}
			else if(s1[2]=='A'&&s2[2]=='B'||s2[2]=='A'&&s1[2]=='B'){
				cout<<"11";
			}
			else if(s1[2]=='B'&&s2[2]=='C'||s2[2]=='B'&&s1[2]=='C'){
				cout<<"11";
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
	return 0;
}
