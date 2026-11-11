#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	cin>>c1>>s1>>c2>>s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(c1==c2){
		cout<<"1";}
	else{
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);	
		return 0;}
	if((s1=="01B"||s2=="01B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="02B"||s2=="02B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="03B"||s2=="03B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="04B"||s2=="04B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;	
	else if((s1=="05B"||s2=="05B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="06B"||s2=="06B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;	
	else if((s1=="07B"||s2=="07B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="08B"||s2=="08B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="09B"||s2=="09B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="10B"||s2=="10B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;	
	else if((s1=="11B"||s2=="11B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="12B"||s2=="12B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;	
	else if((s1=="13B"||s2=="13B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="14B"||s2=="14B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="15B"||s2=="15B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="16B"||s2=="16B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;	
	else if((s1=="17B"||s2=="17B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if((s1=="18B"||s2=="18B")&&(s1!="01D"||s1!="01F"||s2!="01D"||s2!="01F"))
			cout<<111;
	else if(c1=="01D"&&c2=="01F")
		cout<<111;
	else if(c1=="02D"&&c2=="02F")
			cout<<111;
	else if(c1=="03D"&&c2=="03F")
			cout<<111;
	else if(c1=="04D"&&(c2=="04F"))
			cout<<111;
	else if(c1=="05D"&&(c2=="05F"))
			cout<<111;
	else if(c1=="06D"&&(c2=="06F"))
			cout<<111;
	else if(c1=="07D"&&(c2=="07F"))
			cout<<111;
	else if(c1=="08D"&&(c2=="08F"))
			cout<<111;
	else if(c1=="09D"&&(c2=="09F"))
			cout<<111;
	else if(c1=="10D"&&(c2=="10F"))
			cout<<111;
	else if(c1=="11D"&&c2=="11F")
		cout<<111;
	else if(c1=="12D"&&c2=="12F")
			cout<<111;
	else if(c1=="13D"&&(c2=="13F"))
			cout<<111;			
	else if(c1=="14D"&&(c2=="14F"))
			cout<<111;	
	else if(c1=="15D"&&(c2=="15F"))
			cout<<111;
	else if(c1=="16D"&&(c2=="16F"))
			cout<<111;
	else if(c1=="17D"&&(c2=="17F"))
			cout<<111;
	else if(c1=="18D"&&(c2=="18F"))
			cout<<111;	
	else if(c1=="01F"&&(c2=="01D"))
		cout<<111;
	else if(c1=="02F"&&(c2=="02D"))
			cout<<111;
	else if(c1=="03F"&&(c2=="03D"))
			cout<<111;
	else if(c1=="04F"&&(c2=="04D"))
			cout<<111;
	else if(c1=="05F"&&(c2=="05D"))
			cout<<111;
	else if(c1=="06F"&&(c2=="06D"))
			cout<<111;
	else if(c1=="07F"&&(c2=="07D"))
			cout<<111;
	else if(c1=="08F"&&(c2=="08D"))
			cout<<111;
	else if(c1=="09F"&&(c2=="09D"))
			cout<<111;
	else if(c1=="10F"&&(c2=="10D"))
			cout<<111;
	else if(c1=="11F"&&(c2=="12D"))
			cout<<111;
	else if(c1=="12F"&&(c2=="13D"))
			cout<<111;			
	else if(c1=="13F"&&(c2=="14D"))
			cout<<111;	
	else if(c1=="15F"&&(c2=="15D"))
			cout<<111;
	else if(c1=="16F"&&(c2=="16D"))
			cout<<111;
	else if(c1=="17F"&&(c2=="17D"))
			cout<<111;
	else if(c1=="18F"&&(c2=="18D"))
			cout<<111;
	else if(c1=="01D"&&c2=="01F")
		cout<<111;
	else if(c1=="02D"&&c2=="02F")
			cout<<111;
	else if(c1=="03D"&&c2=="03F")
			cout<<111;
	else if(c1=="04D"&&(c2=="04F"))
			cout<<111;
	else if(c1=="05D"&&(c2=="05F"))
			cout<<111;
	else if(c1=="06D"&&(c2=="06F"))
			cout<<111;
	else if(c1=="07D"&&(c2=="07F"))
			cout<<111;
	else if(c1=="08D"&&(c2=="08F"))
			cout<<111;
	else if(c1=="09D"&&(c2=="09F"))
			cout<<111;
	else if(c1=="10D"&&(c2=="10F"))
			cout<<111;
	else if(c1=="11D"&&c2=="11F")
		cout<<111;
	else if(c1=="12D"&&c2=="12F")
			cout<<111;
	else if(c1=="13D"&&(c2=="13F"))
			cout<<111;			
	else if(c1=="14D"&&(c2=="14F"))
			cout<<111;	
	else if(c1=="15D"&&(c2=="15F"))
			cout<<111;
	else if(c1=="16D"&&(c2=="16F"))
			cout<<111;
	else if(c1=="17D"&&(c2=="17F"))
			cout<<111;
	else if(c1=="18D"&&(c2=="18F"))
			cout<<1;
	else
			cout<<000;		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
