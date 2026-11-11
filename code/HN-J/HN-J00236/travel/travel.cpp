#include<bits/stdc++.h>
#include<iostream>
char ca1[3],ca2[3];
char sea1[4],sea2[4];
int a[4];
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca1>>sea1>>ca2>>sea2;
	for(int i=0;i<4;i++){
		a[i]=0;
	}
	if(ca1[0]==ca2[0]&&ca1[1]==ca2[1]){
		a[0]=1;
		if(sea1[0]==sea2[0]&&sea1[1]==sea2[1]){
		a[1]=1;
		if((int(sea1[2])<='C'&&int(sea2[2])<='C')||(int(sea1[2])>'C'&&int(sea2[2])>'C')){
		a[2]=1;
		if(((int(sea1[2])+1)==int(sea2[2]))||((int(sea1[2])-1)==int(sea2[2]))){
			a[3]=1;
		}
	   }
	  }
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
