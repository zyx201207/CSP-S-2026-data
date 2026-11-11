#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int c1,c2;
	string s1,s2,jg;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		jg="0000";
		cout<<jg;
	}
	else{
		jg[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			jg[1]='1';
		}else jg="1000",cout<<jg;
		if(s1[2]=='A'||s1[2]=='C'){
			if(s2[2]=='B'){
				jg="1111";
				cout<<jg;
			}
			else{
				if(s2[2]=='C'||s2[2]=='A'){
					jg="1110";
					cout<<jg;
				}
				else jg="1100",cout<<jg;
			} 
		}
		else{
			if(s1[2]=='B'){
				if(s2[2]=='A'||s2[2]=='C'){
					jg="1111";
					cout<<jg;
				}
				else jg="1100";
				cout<<jg;
			}
			else if(s2[2]=='D'||s2[2]=='F'){
				jg="1111";
				cout<<jg;
			}else jg="1100",cout<<jg;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

