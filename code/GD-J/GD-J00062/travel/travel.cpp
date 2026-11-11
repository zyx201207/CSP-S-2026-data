#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string ter_a,ter_b,ser_a,ser_b;
	int a[10]={},top=0; 
	char ch1=1,ch2=1,ch3=1;
	cin>>ter_a>>ser_a>>ter_b>>ser_b;
	if(ter_a==ter_b) a[++top]=1;
	else{
		a[++top]=0;
		ch1=0;
	}
	if(ser_a[0]==ser_b[0]&&ser_a[1]==ser_b[1]&&ch1) a[++top]=1;
	else{
		a[++top]=0;
		ch2=0;
	}
	if((ser_a[2]=='A'||ser_a[2]=='B'||ser_a[2]=='C')&&(ser_b[2]=='A'||ser_b[2]=='B'||ser_b[2]=='C')&&ch1&&ch2){
		a[++top]=1;
	}else if((ser_a[2]=='D'||ser_a[2]=='F')&&(ser_b[2]=='D'||ser_b[2]=='F')&&ch1&&ch2){
		a[++top]=1;
	}else{
		a[++top]=0;
		ch3=0;
	}
	if(ch1&&ch2&&ch3){
		if(ser_a[2]=='A'&&ser_b[2]=='B') a[++top]=1;
		else if(ser_a[2]=='B'&&(ser_b[2]=='A'||ser_b[2]=='C')) a[++top]=1;
		else if(ser_a[2]=='C'&&ser_b[2]=='B') a[++top]=1;
		else if(ser_a[2]=='D'&&ser_b[2]=='F') a[++top]=1;
		else if(ser_a[2]=='F'&&ser_b[2]=='D') a[++top]=1;
		else a[++top]=0;
	}else a[++top]=0;
	for(int i=1;i<=4;i++) cout<<a[i];
	return 0;
}
