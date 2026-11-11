#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int x=0,y=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<s1.size()-1;i++){
			
			x=x*10+(s1[i]-'0');
			y=y*10+(s2[i]-'0');
		}
		//cout<<endl<<x<<" "<<y<<endl;
		if(x==y){
			cout<<"1";
			if('A'<=s1[2] && s1[2]<='C' && 'A'<=s2[2] && s2[2]<='C'){
				cout<<"1";
				if(s1[2]=='C'){
					if(x+1==y || x-1==y && s1[2]==s2[2]) cout<<"1";
					else if(x==y && s1[2]-'A'-1==s2[2]-'A') cout<<"1";
					else cout<<"0";
				}
				else{
					if(x+1==y || x-1==y && s1[2]==s2[2]) cout<<"1";
					else if(x==y && s1[2]-'A'-1==s2[2]-'A' || s1[2]-'A'+1==s2[2]-'A') cout<<"1";
					else cout<<"0";
				}
			}
			else if('D'<=s1[2] && s1[2]<='F' && 'D'<=s2[2] && s2[2]<='F'){
				cout<<"1";
				if(s1[2]=='D'){
					if(x+1==y || x-1==y && s1[2]==s2[2]) cout<<"1";
					else if(x==y && s1[2]-'A'+1==s2[2]-'A') cout<<"1";
					else cout<<"0";
				}
				else{
					if(x+1==y || x-1==y && s1[2]==s2[2]) cout<<"1";
					else if(x==y && s1[2]-'A'-1==s2[2]-'A' || s1[2]-'A'+1==s2[2]-'A') cout<<"1";
					else cout<<"0";
				}
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
