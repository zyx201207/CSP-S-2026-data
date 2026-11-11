#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cnt=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			char s=char(s1[2]);
			char s6=char(s2[2]);
			if(s=='D'&&s6=='F'||s=='F'&&s6=='D'){
				cout<<"1";
				cout<<"1";
			}else if(s>='A'&&s<='C'&&s6>='A'&&s6<='C'){
				cout<<"1";
				s=s+1;
				if(s==s6){
					cout<<"1";
					cnt++;
				}else{
					cout<<"0";
					cnt++;
				}
				if(cnt==0){
					s=s-2;
					if(s==s6){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}	
			}else{
				cout<<"00";
			}
			
		}else{
			cout<<"000";
		}
		
	}else{
		cout<<"0000";
	}
	
	
return 0;	
}

