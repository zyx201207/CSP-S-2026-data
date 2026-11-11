#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	f1=false;f2=false;f3=false;f4=false;
	cin>>c1>>s1>>c2>>s2;
	int x=(s1[0]-'0')*10+s1[1]-'0',y=(s2[0]-'0')*10+s2[1]-'0';
	char xx=s1[2],yy=s2[2];
	if(c1==c2){
		f1=true;
		if(x==y){
			f2=true;
			if((xx=='A'||xx=='B'||xx=='C')&&(yy=='A'||yy=='B'||yy=='C')){
				f3=true;
				if((xx=='A'||xx=='C')&&(yy=='A'||yy=='C'))f4=false;
				else f4=true;
			}
			if((xx=='D'||xx=='F')&&(yy=='D'||yy=='F'))f3=true,f4=true;
		}
	}
	cout<<f1<<f2<<f3<<f4;
	fclose(stdin);fclose(stdout);
	return 0;
} 
