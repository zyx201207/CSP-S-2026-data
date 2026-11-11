#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ff,fff,ffff="ABCDF";
bool f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)f=0;
	cout<<f;
	ff=s1[0]+s1[1];
	fff=s2[0]+s2[1];
	if(ff!=fff)f=0;
	cout<<f;
	ff=s1[2],fff=s2[2];
	if(ff>fff)swap(ff,fff);
	if(fff=="D"||(fff>="D"&&ff<"D"))f=0;
	cout<<f;
	for(int i=0;i<5&&f;i++){
		if(i==5)f=0;
		else if(ffff[i]==ff[0]&&(fff[0]!=ffff[i+1]||(fff[0]==ffff[i+1]&&i==2)))f=0;
	}
	cout<<f;
	return 0;
}
