#include<bits/stdc++.h>
using namespace std;
int f(char a,char b){
	if(abs((int)b-(int)a)==1){
		if((int)a+(int)b==135){
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(abs((int)b-(int)a)==2 and (int)a+(int)b==138){
		return 1;
	} 
	else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1] and c1[0]==c2[0]){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	if(s1[0]==s2[0] and s1[1]==s2[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	
	if((int)s1[2]>=65 and (int)s1[2]<=67 and (int)s2[2]>=65 and (int)s2[2]<=67){
		cout<<1;
	}
	else if((int)s1[2]>=68 and (int)s1[2]<=70 and (int)s2[2]>=68 and s2[2]<=70){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	cout<<f(s1[2],s2[2]);
		
	
	return 0;
} 
