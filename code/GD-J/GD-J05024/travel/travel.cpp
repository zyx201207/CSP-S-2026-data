#include<bits/stdc++.h>
using namespace std;
int c1,c2;
bool f=1;
string s1,s2;
int p1,p2,z1,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	p1=stoi(s1.substr(0,2));
	p2=stoi(s2.substr(0,2));
	z1=s1[2]-'A'+1;
	z2=s2[2]-'A'+1;
	if(z1==6) z1--;
	if(z2==6) z2--;
	if(c1==c2) cout<<"1";
	else cout<<"0",f=0;
	if(f==1&&p1==p2) cout<<"1";
	else cout<<"0",f=0;
	if(f==1&&(z1<=3&&z2<=3||z1>=4&&z2>=4)) cout<<"1";
	else cout<<"0",f=0;
	if(z1>z2) swap(z1,z2);
	if(f==1&&(z1==1&&z2==2||z1==2&&z2==3||z1==4&&z2==5)) cout<<"1";
	else cout<<"0";
	return 0;
}
