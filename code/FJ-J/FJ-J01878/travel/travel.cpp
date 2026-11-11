#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;

	int c,s,sum=0;
	cin>>c1>>c2>>s1>>s2;
	c=(c2[0]-'0')*10+(c2[1]-'0');
	s=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1==s1){
		cout<<"1";
		sum++;
		if(c==s){
				cout<<"1";
				sum++;
			if(((c2[2]=='A'||c2[2]=='C'||c2[2]=='B')&&(s2[2]=='A'||s2[2]=='C'||s2[2]=='B'))||(c2[2]=='F'||c2[2]=='D')&&(s2[2]=='F'||s2[2]=='D')){
					cout<<"1";
					sum++;
				if((c2[2]-'A'+1==s2[2]-'A')||(s2[2]-'A'+1==c2[2]-'A'));
					cout<<"1";
					sum++;
			}
		}
	}
	for(int i=1;i<=4-sum;i++){
		cout<<"0";
	}
}
