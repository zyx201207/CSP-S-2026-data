#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int bel[5]{};
	bel[0]=bel[1]=bel[2]=1;
	bel[3]=bel[4]=2;
	if(s1[2]=='F') s1[2]='E';
	if(s2[2]=='F') s2[2]='E'; 
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			if(bel[s1[2]-'A']==bel[s2[2]-'A']){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
