#include<bits/stdc++.h>
using namespace std;
int s1,s2;
int c1,c2;
char al1,al2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>al1>>c2>>s2>>al2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	else cout<<1; 
	if(al1>al2){
		char a=al1;
		al1=al2;
		al2=a;
	}
	if(al2<='C')cout<<1;
	else if(al1=='D')cout<<1;
	else {
		cout<<"00";
		return 0;
	} 
	if(al2-al1==1){
		if(al2!='D'){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		if(al2-al1==2&&al2=='F'){
			cout<<1;
		}
		else cout<<0;
	}
	
	return 0;
}
