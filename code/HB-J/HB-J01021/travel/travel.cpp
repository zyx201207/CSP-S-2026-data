#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a='0',b='0',c='0',d='0';
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			b='1';
			if((s1[2]=='F' and s2[2]=='D')or(s1[2]=='D' and s2[2]=='F')or(s1[2]<='C' and s1[2]>='A' and s2[2]<='C' and s2[2]>='A')){
				c='1';
				if(s1[2]=='F' or s1[2]=='E' or (s1[2]=='A' and s2[2]=='B')or (s1[2]=='B' and (s2[2]=='A' or s2[2]=='C'))or (s1[2]=='C' and s2[2]=='B')){
					cout<<"1111"<<endl;
				}
				else{
					cout<<"1110"<<endl;
				}
			}
			else{
				cout<<"1100"<<endl;
				return 0;
			}
		}
		else{
			cout<<"1000"<<endl;
			return 0;
		}
	}
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	return 0;
}
