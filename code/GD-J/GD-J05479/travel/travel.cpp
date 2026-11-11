#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int a[4]={0,0,0,0},p1,p2;
int l1,l2;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	a[0]=1;
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	l1=s1[2]-'A';
	if(l1==5) l1--;
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	l2=s2[2]-'A';
	if(l2==5) l2--;
	if(p1==p2){
	a[1]=1;
	if(((l1>2)&&(l1>2)) or ((l1<=2)&&(l1<=2))){
	a[2]=1;
	if(abs(l1-l2)==1) a[3]=1;
	
	}}}
	for(int i=0;i<4;i++)	cout<<a[i];

}
