#include<bits/stdc++.h>
using namespace std;
char a[5],b[5];
string n;
string m;
int nn,mm;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0]>>a[1]>>n;
	cin>>b[0]>>b[1]>>m;
	if(m[2]=='A') m[2]=1;
	else if(m[2]=='B') m[2]=2;
	else if(m[2]=='C') m[2]=3;
	else if(m[2]=='D') m[2]=6;
	else if(m[2]=='F') m[2]=7;
	if(n[2]=='A') n[2]=1;
	else if(n[2]=='B') n[2]=2;
	else if(n[2]=='C') n[2]=3;
	else if(n[2]=='D') n[2]=6;
	else if(n[2]=='F') n[2]=7;
	if(a[0]==b[0] && a[1]==b[1]){
		if((n[0]-'0')*10+(n[1]-'0')==(m[0]-'0')*10+(m[1]-'0')){
			if(max((n[2]-'0'),(m[2]-'0'))-min((n[2]-'0'),(m[2]-'0'))<=2){
				if(max((n[2]-'0'),(m[2]-'0'))-min((n[2]-'0'),(m[2]-'0'))==1) cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

