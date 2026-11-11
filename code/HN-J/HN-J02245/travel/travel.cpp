#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,S1="",S2="";
char Ss1,Ss2;
int main()
{
	frepoen(".in","r",stdin);
	frepoen(".out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<s1.size()-1;i++){
			S1+=s1[i];
		}
		for(int i=0;i<s2.size()-1;i++){
			S2+=s2[i];
		}
		if(S1==S2){
			cout<<"1";
				Ss1=s1[2];
				Ss2=s2[2];
			if(((Ss1=='A'||Ss1=='B'||Ss1=='C')&&(Ss2=='A'||Ss2=='B'||Ss2=='C'))||((Ss1=='D'||Ss1=='E')&&(Ss2=='D'||Ss2=='E'))){
				cout<<"1";
				if((Ss1+1==Ss2)||(Ss1-1==Ss2)){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
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
