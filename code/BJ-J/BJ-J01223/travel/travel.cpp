#include<iostream>
#include<cmath>
using namespace std;

string c1,s1,c2,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int car1,car2;
    car1=(c1[0]-0x30)*10+(c1[1]-0x30);
    car2=(c2[0]-0x30)*10+(c2[1]-0x30);
    if(car1==car2){
    	cout<<1;
    	int line1,line2;
		line1=(s1[0]-0x30)*10+(s1[1]-0x30);
		line2=(s2[0]-0x30)*10+(s2[1]-0x30);
		if(line1==line2){
			cout<<1;
			char seat1=s1[2],seat2=s2[2];
			if((seat1<='C'&&seat2<='C')||(seat1>='D'&&seat2>='D'))cout<<1;
			else cout<<0;
			if((seat1<='C'&&seat2<='C'&&abs(seat2-seat1)==1)||(seat1>='D'&&seat2>='D'&&abs(seat2-seat1)==2))cout<<1;
			else cout<<0;
		}else cout<<"000";
    }
    else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}