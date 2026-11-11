#include<bits/stdc++.h>
using namespace std;
char s1[5],s2[5];
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int z1,p1,z2,p22;
	z1=(int)s1[2]-'A'+1;
	z2=(int)s2[2]-'A'+1;
	p1=((int)s1[0]-'0')*10+((int)s1[1]-'0');
	p22=((int)s2[0]-'0')*10+((int)s2[1]-'0');
	if(c1==c2) cout<<"1";
	else if(c1!=c2) {
		cout<<"0000";
		return 0;
	}
	if(p1==p22) cout<<1;
	else if(p1!=p22) {
		cout<<"000";
		return 0;
	}
	if((z1<=3&&z2<=3)||(z1>3&&z2>3)) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if((min(z1,z2)==1&&max(z1,z2)==2)||(min(z1,z2)==2&&max(z1,z2)==3)||(min(z1,z2)==4&&max(z1,z2)==6)) cout<<1;
	else cout<<0;
	return 0;
}
