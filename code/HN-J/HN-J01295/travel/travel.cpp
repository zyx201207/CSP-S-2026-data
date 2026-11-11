#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	string a1,a2,a3,b1,b2,b3;
	for(int i=0;i<3;i++){
		a1+=cin.get();
	}
	for(int i=0;i<2;i++){
		a2+=cin.get();
	}
	a3+=cin.get();
	cin.get();
	for(int i=0;i<3;i++){
		b1+=cin.get();
	}
	for(int i=0;i<2;i++){
		b2+=cin.get();
	}
	b3+=cin.get();
	if(a1==b1){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2==b2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(((a3=="A" || a3=="B" || a3=="C")&&(b3=="A" || b3=="B" || b3=="C")) || ((a3=="D" || a3=="F")&&(b3=="D" || b3=="F"))){
		if((a3=="D" || a3=="F")&&(b3=="D" || b3=="F")){
			cout<<"11";
			return 0;
		}
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((a3=="A" && b3=="B") || (a3=="B" && b3=="C") || (a3=="B" && b3=="A") || (a3=="C" && b3=="B")){
		cout<<1;
	}else{
		cout<<"0";
	}
	return 0;
}
