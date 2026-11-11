#include<bits/stdc++.h>
using namespace std;
int a,b;
string c1,s1,c2,s2;
int main (){ 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>a>>s1>>c2>>b>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	 if(a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	if(((s1=="A"|| s1=="B" || s1=="C") && (s2=="A"|| s2=="B" || s2=="C")) || ((s1=="F" || s1=="D") && (s2=="F" || s2=="D"))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1=="A" && s2=="B"){
		cout<<1;
	}else if(s1=="B" && (s2=="C" || s2=="A")){
	cout<<1;
	}else if(s1=="C" && s2=="B"){
	cout<<1;
	}else if((s1=="F" && s2=="D")||(s1=="D" && s2=="F")){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
