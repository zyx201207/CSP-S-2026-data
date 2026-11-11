#include<bits/stdc++.h>

using namespace std;
bool side(string s){//a,b,c 0; d,e 1;
	return (s[2]=='D'||s[2]=='F');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//车厢
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){// 同一排
			cout<<"1";
			if(side(s1)==side(s2)){// 同一排
				cout<<"1";
				if((int)s1[2]==((int)s2[2]+1)||
					(int)s1[2]==((int)s2[2]-1)/*ABC*/||
					(side(s1)==1&&side(s2)==1)){
					cout<<"1";
				}else{
					cout<<"0";
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
