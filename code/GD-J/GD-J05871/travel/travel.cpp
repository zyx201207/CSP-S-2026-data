#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	string x,y;
	x=s1[0]+s1[1];
	y=s2[0]+s2[1];
	if(x!=y){
		cout<<"1000";
		return 0;
	}
	char m,n;
	m=s1[2];
	n=s2[2];
	if(m>='D' && n>='D'){
		cout<<"1111";
		return 0;
	}	
	if(m<'D' && n<'D'){
		if(m=='B' || n=='B'){
			cout<<"1111";
			return 0;
		}
		else {
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1100";
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
