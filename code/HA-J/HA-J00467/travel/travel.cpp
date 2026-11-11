#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,pai1,pai2,let1,let2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	pai1+=s1[0];
	pai1+=s1[1];
	pai2+=s2[0];
	pai2+=s2[1];
	if(pai1==pai2)cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	let1+=s1[2];
	let2+=s2[2];
	if(let1=="A"||let1=="B"||let1=="C"){
		if(let2=="A"||let2=="B"||let2=="C")cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
	}
	else if(let1=="D"||let1=="F"){
		if(let2=="D"||let2=="F")cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
	}
	
	
	if(let1=="A"&&let2=="B")cout<<"1";
	else if(let1=="B"&&let2=="A")cout<<"1";
	else if(let1=="B"&&let2=="C")cout<<"1";
	else if(let1=="C"&&let2=="B")cout<<"1";
	else if(let1=="D"&&let2=="F")cout<<"1";
	else if(let1=="F"&&let2=="D")cout<<"1";
	else cout<<"0";
	return 0;
}
