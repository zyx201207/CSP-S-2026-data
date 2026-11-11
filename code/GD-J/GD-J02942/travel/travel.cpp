#include<bits/stdc++.h>

using namespace std;
long long a[4];
char ch1,ch2,sh1,sh2,sh3,sh4;
long long ch_1,ch_2,sh_1,sh_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ch1>>ch2;
	if(ch1=='0'){
		ch_1=ch2-'0';
	}
	else{
		ch_1+=10;
		ch_1+=ch2-'0';
	}
	cin>>sh1>>sh2>>sh3;
	if(sh1=='0'){
		sh_1=sh2-'0';
	}
	else{
		sh_1+=10;
		sh_1+=sh2-'0';
	}
	cin>>ch1>>ch2;
	if(ch1=='0'){
		ch_2=ch2-'0';
	}
	else{
		ch_2+=10;
		ch_2+=ch2-'0';
	}
	cin>>sh1>>sh2>>sh4;
	if(sh1=='0'){
		sh_2=sh2-'0';
	}
	else{
		sh_2+=10;
		sh_2+=sh2-'0';
	}//ch_1是小R车厢号，ch_2是小X车厢号
	//sh_1是小R座位号，sh_2是小x座位号
	//sh3,sh4
	//同一车厢
	if(ch_1==ch_2){
		cout<<1;
		a[0]=1;
	} 
	else cout<<0;
	if(sh_1==sh_2&&a[0]==1){
		cout<<1;
		a[1]=1;
	} 
	else cout<<0; 
	//cout<<'\n';
	if((sh3=='A'||sh3=='B'||sh3=='C')&&a[0]==1&&a[1]==1){
		if(sh4=='A'||sh4=='B'||sh4=='C'){
			cout<<1;
			a[2]=1;
		}
		else cout<<0;
	}
	else if(sh3=='D'||sh3=='F'&&a[0]==1&&a[1]==1){
		if(sh4=='D'||sh4=='F'){
			cout<<1;
			a[2]=1;
		}
		else cout<<0;
	}
	else cout<<0;
	if(a[0]==1&&a[1]==1&&a[2]==1){
		if(sh3=='A'&&sh4=='C'||sh3=='C'&&sh4=='A') cout<<0;
		else cout<<1;
	}
	else cout<<0;
	return 0;
}
