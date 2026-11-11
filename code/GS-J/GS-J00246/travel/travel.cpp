#include<bits/stdc++.h>
using namespace std;
int a[5];
char s1[4];
char s2[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel,out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin >> c1;
	for(int i=1;i<=3;i++){
		cin >> s1[i];
	}
	cin >> c2;
	for(int i=1;i<=3;i++){
		cin >> s2[i];
	}
	if(c1==c2){
	    a[1]=1;
	}else{
		a[1]=0;
	}
	if((s1[1]==s2[1])&&(s2[2]==s1[2])&&(a[1]==1)){
		a[2]=1;
	}else{
		a[2]=0;
	}
	if((((s1[3]<'D')&&(s2[3]<'D'))||((s1[3]>'C')&&(s2[3]>'C')))&&(a[2]==1)){
		a[3]=1;
	}else{
		a[3]=0;
	}
	if((((s1[3]<'C')&&(s2[3]<'C'))||((s1[3]>'C')&&(s2[3]>'C'))||(((s1[3]>'A')&&(s2[3]>'A'))&&((s1[3]<'C')&&(s2[3]<'C')))&&(a[3]==1))){
		a[4]=1;
	}else{
		a[4]=0;
	}
	for(int i=1;i<=4;i++){
		cout << a[i];
	}
	return 0;
}
