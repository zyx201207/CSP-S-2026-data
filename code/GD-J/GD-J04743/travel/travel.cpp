#include<bits/stdc++.h>
using namespace std;
char data[10];
bool b1=false,b2=false,b3=false;
int b4=0,b5=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<10;i++){
		cin>>data[i];
	}
	if(data[0]==data[5]&&data[1]==data[6]){
		cout<<1;
		b1=1;
	}
	else
		cout<<0;
	if(b1&&data[2]==data[7]&&data[3]==data[8]){
		cout<<1;
		b2=1;
	}
	else
		cout<<0;
	if(data[4]=='A'||data[4]=='B'||data[4]=='C')
		b4=1;
	if(data[9]=='A'||data[9]=='B'||data[9]=='C')
		b5=1;
	if(b1&&b2&&b4==b5){
		cout<<1;
		b3=1;
	}
	else
		cout<<0;
	if(b1&&b2&&b3&&((b4==1&&(data[4]==data[9]+1||data[4]==data[9]-1))||(b4==0&&data[4]==data[9]+2||data[4]==data[9]-2)))
		cout<<1;
	else
		cout<<0;
	return 0;
}
