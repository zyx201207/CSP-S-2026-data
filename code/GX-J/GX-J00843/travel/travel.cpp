#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[1]==s2[1] and s1[2]==s2[2]){
			cout<<1;
			if(((s1[3]=='A' or s1[3]=='B' or s1[3]=='C')&&(s2[3]=='A' or s2[3]=='B' or s2[3]=='C')) or ((s1[3]=='D' or s1[3]=='E')&&(s2[3]=='D' or s2[3]=='E'))){
				cout<<1;
				if((s1[3]=='D' or s1[3]=='E')&&(s2[3]=='D' or s2[3]=='E'))cout<<1;
				else if((s1[3]=='A' or s1[3]=='B')&&(s2[3]=='B' or s2[3]=='A'))cout<<1;
				else if((s1[3]=='B' or s1[3]=='C')&&(s2[3]=='B' or s2[3]=='C'))cout<<1;
				else cout<<0;
			}else cout<<00;
		}else cout<<000;
	}
	else cout<<0000;
	return 0;
}
