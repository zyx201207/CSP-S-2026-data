#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1>=1&&c1<=18&&c2>=1&&c2<=18){
		if(c1==c2&&c1!=01&&c1!=16){
		cout<<"1";	
	}
	else{
		cout<<"0";
	}
	if(c1==c2&&c1!=01&&c1!=16&&s1=="02D"&&s1=="02F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="03D"&&s1=="03F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="04D"&&s2=="04F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="05D"&&s2=="05F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="06D"&&s2=="06F"){
		cout<<"111";	
	}
		else if(c1==c2&&c1!=01&&c1!=16&&s1=="07D"&&s2=="07F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="08D"&&s2=="08F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="09D"&&s2=="09F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="10D"&&s2=="10F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="11D"&&s2=="11F"){
		cout<<"111";
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="12D"&&s2=="12F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="13D"&&s2=="13F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="14D"&&s2=="14F"){
		cout<<"111";	
	}
	else if(c1==c2&&c1!=01&&c1!=16&&s1=="15D"&&s2=="15F"){
		cout<<"111";	
	}

	else if(c1==c2&&c1!=01&&c1!=16&&s1=="17D"&&s2=="17F"){
		cout<<"111";	
	}
	else{
		cout<<"000";
	}
	}
	
	return 0;
}
