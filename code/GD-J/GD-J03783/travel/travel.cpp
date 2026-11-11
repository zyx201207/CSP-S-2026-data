#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
int x,y;
bool a=1,b=1,c=1,d=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){a=0;b=0;c=0;d=0;}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){b=0;c=0;d=0;break;}
	}
	x=s1[2]-'A'+1;y=s2[2]-'A'+1;
	if(x<=3 && y>3){c=0;d=0;}
	else if(x>3 && y<=3){c=0;d=0;}
	if(abs(x-y)!=1 || (x==3 && y==4)){d=0;}
	cout<<a<<b<<c<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
