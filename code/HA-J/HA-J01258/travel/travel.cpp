#include<bits/stdc++.h>
using namespace std;
string c;
string s;
string a;
string b;
string j;
bool y=0;
char p[4]={'A','A','B','C'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>a>>b;
	for(int i=1;i<=3;i++){
			if(s[2]=p[i]){
				for(int j=i-1;j<=i+1;j++){
					if(b[2]==p[j]) y=true;
				}
			}	
	} 
	if((c[0]-'0'==a[0]-'0')&&(c[1]-'0'==a[1]-'0')){
		j[1]='1';
		if((s[0]-'0'==b[0]-'0')&&(s[1]-'0'==b[1]-'0')){
			j[2]='1';
			if(y==true){
				j[3]='1';
				if(s[2]+1==b[2]||s[2]-1==b[2]){
					j[4]='1';
				}else {
					j[4]='0';
				}
			}else if((s[2]=='F'&&b[2]=='D')||(s[2]=='D'&&b[2]=='D')){
				j[4]='1';
				j[3]='1';
				
			}else{
				j[3]='0';
				j[4]='0';
			}	
		}else{
			j[2]='0';
			j[3]='0';
			j[4]='0';
		}
	}else {
		j[1]='0';
		j[2]='0';
		j[3]='0';
		j[4]='0';
	}
	for(int i=1;i<=4;i++){
		cout<<j[i];
	}
	return 0;
}
