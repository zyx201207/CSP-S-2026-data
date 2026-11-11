#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int n,m;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	n=(s1[0]-'0')*10+s1[1]-'0',m=(s2[0]-'0')*10+s2[1]-'0';
	a=s1[2]-'A'+1,b=s2[2]-'A'+1;
	if(a==6)a--;
	if(b==6)b--;
	if(c1==c2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(n==m)cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	if((a<=3&&b>=4)||(a>=4&&b<=3)){
		cout<<"00";
		return 0;
	}
	else {
		cout<<"1";
	}
	if(abs(a-b)==1)cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
