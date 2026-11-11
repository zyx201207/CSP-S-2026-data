#include<bits/stdc++.h>
using namespace std;
int main(){
	string n,m,n1[5],m1[5];
	char nn[5],mm[5];
	cin>>n>>nn>>m>>mm;
	for(int i=0;i<=2;i++){
		n1[i]=nn[i];
		m1[i]=mm[i];
	}
	if(n!=m||n=="01"||n=="16"||m=="01"||m=="16"){
		cout<<"0000";
		return 0;
	}
	if(n==m){
		cout<<"1";
	}
	if(n1[0]==m1[0]&&n1[1]==m1[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(n1[2]=="F"&&m1[2]=="D"||n1[2]=="D"&&m1[2]=="F"){
		cout<<"11";
	}
	else if(n1[2]=="A"&&m1[2]=="B"||n1[2]=="B"&&m1[2]=="A"||n1[2]=="B"&&m1[2]=="C"||n1[2]=="C"&&m1[2]=="B"){
		cout<<"11";
	}
	else if(n1[2]=="A"&&m1[2]=="C"||n1[2]=="C"&&m1[2]=="A"){
		cout<<"10";
	}
	else{
		cout<<"00";
	}
	freopen("travrl.in","r",stdin);
	freopen("travel.out","w",stdout);
	return 0;
} 
