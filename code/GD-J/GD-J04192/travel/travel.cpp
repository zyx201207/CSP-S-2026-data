#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	bool oka=true;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
		oka=false;
	}
	
	if(oka && s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}
	else{
		cout<<0;
		oka=false;
	}
	
	if(oka && ((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D'))){
		cout<<1;
	}
	else{
		cout<<0;
		oka=false;
	}
	
	if(oka && abs(s1[2]-s2[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	return 0;
}
