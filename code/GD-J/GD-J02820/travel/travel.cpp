#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]+s1[1]==s2[0]+s2[1]){
		cnt+='?';
	}
	else{
		cout<<"1000";
		return 0;
	}
	char x=s1[2],y=s2[2];
	if(x>='A' && x<='C' && y>='A' && y<='C' || x=='D' && y=='F' || x=='F' && y=='D'){
		cnt+='?';
	}
	else{
		cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2; 
		cout<<"1100";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		cnt+='?';
	}
	else{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
