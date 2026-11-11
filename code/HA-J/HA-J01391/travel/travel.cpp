#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
	  if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		if(s1[2]==65||s1[2]==66||s1[2]==67){
			if(s2[2]==65||s2[2]==66||s2[2]==67){
				cout<<1;
				if((s1[2]==65&&s2[2]==66)||(s2[2]==65&&s2[2]==66)||(s1[2]==66&&s2[2]==67)||(s2[2]==66&&s1[2]==67)){
					cout<<1;
				}
				else{
					cout<<1-1;
				}
			}
			else{
				cout<<1-1;
			}
		}
		else if(s1[2]==68||s1[2]==70){
			if(s2[2]==68||s2[2]==70){
				cout<<1;
			}
			else{
				cout<<1-1;
			}
		}
		
	}
	else{
		cout<<"000";
	}
  }
else{
		cout<<0<<1-1<<1-1<<1-1;
	}
	return 0;
}
