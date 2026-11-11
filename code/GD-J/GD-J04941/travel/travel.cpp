#include<bits/stdc++.h>
using namespace std;
char a[3];
char a2[5];
char b[3],b2[5];
int xx,yy;
int x,y,t,z;
bool R=0,X=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",a+1,a2+1,b+1,b2+1);
	if(a[1]=='0') x=a[2]-'0';	
	else x=10+a[2]-'0';
	if(b[1]=='0') y=b[2]-'0';	
	else y=10+b[2]-'0';;
	if(a2[1]=='0') t=a2[2]-'0';	
	else x=10+a2[2]-'0';
	if(b2[1]=='0') z=b2[2]-'0';	
	else z=10+b2[2]-'0';
	if(a2[3]=='F'||a2[3]=='D') R=1;
	if(b2[3]=='F'||b2[3]=='D') X=1;
	xx=a2[3]-'A'+1;
	yy=b2[3]-'A'+1;
	if(a2[3]=='F'){
		xx--;
	}
	if(b2[3]=='F'){
		yy--;
	}
	if(x==y) {
		cout<<1;
		if(b2[1]==a2[1]&&a2[2]==b2[2]){
			cout<<1;
			if(R==X){
				cout<<1;
				if(xx-1==yy||xx+1==yy){
					cout<<1;
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
