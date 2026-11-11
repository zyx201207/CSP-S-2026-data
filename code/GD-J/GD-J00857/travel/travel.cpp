#include<bits/stdc++.h>
using namespace std;
int C1,C2;
char S1[3]={'0'},S2[3]={'0'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C1>>S1>>C2>>S2;
	if(C1==C2){
		cout<<1;
		if((S1[1]==S2[1])){
			cout<<1;
			if((S1[2]<='C'&&S1[2]>='A'&&S2[2]<='C'&&S2[2]>='A')|| (S1[2]+S2[2])==('D'+'F')){
				cout<<1;
				if(abs(S1[2]-S2[2])==1)
					{cout<<1;}
				else
					{cout<<0;}
				return 0;
		}}
		else cout<<0;
		cout<<0;
		cout<<0;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
