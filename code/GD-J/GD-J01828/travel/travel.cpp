#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string Rowa;
	string Sa;
	string Rowb;
	string Sb;
	cin >>Rowa>>Sa>>Rowb>>Sb;
	int a , b;
	if(Rowa[0]=='0'){
		a=Rowa[1]-'0';
	}
	else{
		a=(Rowa[0]-'0')*10+Rowa[1]-'0';
	}
	if(Rowb[0]=='0'){
		b=Rowb[1]-'0';
	}
	else{
		b=(Rowb[0]-'0')*10+Rowb[1]-'0';
	}
	string ans="";
	bool Same_Room , Same_Row;
	if(a==b){
		ans+="1";
		Same_Room=true;
	}
	else{
		ans+="0";
		Same_Room=false;
	}
	if((Sa[0]==Sb[0]&&Sa[1]==Sb[1])&&(Same_Room==true)){
		ans+="1";
		Same_Row=true;
	}
	else{
		ans+="0";
		Same_Row=false;
	}
	if(Sa[2]=='A'||Sa[2]=='B'||Sa[2]=='C'){
		if((Sb[2]=='A'||Sb[2]=='B'||Sb[2]=='C')&&(Same_Row==true)){
			ans+="1";
		}
		else{
			ans+="0";
		}
		if((abs(Sa[2]-Sb[2])==1)&&(Sa[2]!='D'&&Sb[2]!='D')&&(Same_Row==true)){
			ans+="1";
		}
		else{
			ans+="0";
		}
	}
	if(Sa[2]=='D'||Sa[2]=='F'){
		if(Sb[2]=='D'||Sb[2]=='F'&&Same_Row==true){
			ans+="1";
		}
		else{
			ans+="0";
		}
		if(Sa[2]=='F'&&Sb[2]=='D'&&Same_Row==true){
			ans+="1";
		}
		else{
			ans+="0";
		}
	}
	cout <<ans;
	return 0;
} 
