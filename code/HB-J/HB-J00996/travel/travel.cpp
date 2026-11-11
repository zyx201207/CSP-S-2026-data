#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a[10];
int b[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
		int flag1=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			flag1=0;
		}
	}
	if(flag1!=0){
		a[2]=1;
		int f1=2,f2=2;
	if(s1[2]=='A')f1=1;
	if(s1[2]=='B')f1=1;
	if(s1[2]=='C')f1=1;
	if(s2[2]=='A')f2=1;
	if(s2[2]=='B')f2=1;
	if(s2[2]=='C')f2=1;
	if(f1==f2){
		a[3]=1;
		int f11,f22;
	if(s1[2]=='A')f11=1;
	if(s1[2]=='B')f11=2;
	if(s1[2]=='C')f11=3;
	if(s1[2]=='D')f11=4;
	if(s1[2]=='E')f11=5;
	if(s2[2]=='A')f22=1;
	if(s2[2]=='B')f22=2;
	if(s2[2]=='C')f22=3;
	if(s2[2]=='D')f22=4;
	if(s2[2]=='E')f22=5;
	if(f11==f22+1){
		a[4]=1;
	}else if(f11+1==f22){
		a[4]=1;
	}
	}
	}
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
			}
	
	
	return 0;
}
