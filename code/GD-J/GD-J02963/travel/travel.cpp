#include<bits/stdc++.h>
using namespace std;
string s1,s2,a,b;
char c1,c2;
int n1,n2;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	c1=s1[2]; 
	c2=s2[2];
	n1=(int)s1[0]*10+(int)s1[1];
	n2=(int)s2[0]*10+(int)s2[1];
	if (a==b){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	
	
	if (n1==n2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	
	if ((c1==c2+1 || c1+1==c2) && !((c1=='C' && c2=='D') || (c1=='D' && c2=='C'))){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	
	if (c1==c2+1 || c1+1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
