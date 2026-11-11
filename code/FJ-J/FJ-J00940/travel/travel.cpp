#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool flag=true;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<"1";
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]) flag=false;
		}
		if(!flag) cout<<"000";
		else{
			cout<<"1";
			if((s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F')||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
					cout<<"1";
				}	
				else cout<<"0";
			}
			else{
				cout<<"00";
			}
		}
	}
	return 0;
 } 
