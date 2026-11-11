#include<bits/stdc++.h>
using namespace std;

string c_1,s_1,c_2,s_2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<"1";
		string p_1="..",p_2="..";
		char n_1,n_2;
		p_1[0]=s_1[0]; p_1[1]=s_1[1];
		p_2[0]=s_2[0]; p_2[1]=s_2[1];
		if(p_1==p_2){
			cout<<"1";
			n_1=s_1[2]; n_2=s_2[2];
			if(n_1>='A' && n_1<='C' && n_2>='A' && n_2<='C') cout<<"1";
			else if(n_1=='D' && n_2=='F' || n_1=='F' && n_2=='D') cout<<"1";
			else cout<<"0";
			if(n_1=='A' && n_2=='B' || n_1=='B' && n_2=='C' || n_1=='D' && n_2=='F') cout<<"1";
			else if(n_1=='B' && n_2=='A' || n_1=='C' && n_2=='B' || n_1=='F' && n_2=='D') cout<<"1";
			else cout<<"0";
			cout<<"\n";
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
	}
	
	return 0;
} 
