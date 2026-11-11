#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char st1=s1[0]+s1[1],st2=s2[0]+s2[1];
	bool f1=0,f2=0;
	
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(st1!=st2){
		cout<<"1000";
		return 0;
	}
	if(s1[2]<='C') f1=1;
	if(s2[2]<='C') f2=1;
	if(f2!=f1){
		cout<<"1100";
		return 0;
	}
	if((int(s1[2])+1==int(s2[2]))||(int(s2[2])+1==int(s1[2]))){
		cout<<"1110";
		return 0;
	}
	
	cout<<"1111";
	return 0;
	
	
}
