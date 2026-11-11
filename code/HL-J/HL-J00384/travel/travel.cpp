#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1=0,f2=0,f3=0;
	//第一种// 
	if(c1==c2){
		cout<<1;
		f1=1;	
	}
	else cout<<0;
	
	//第二种//
	string h1=s1.substr(0,2); 
	string h2=s2.substr(0,2);
	if(h1==h2&&f1){
		cout<<1;
		f2=1;
	}
	else cout<<0;
	
	//第三种//
	map<string,int>g;
	g["A"]=1;
	g["B"]=1;
	g["C"]=1;
	g["D"]=2;
	g["F"]=2;
	string g1=s1.substr(2);
	string g2=s2.substr(2);
	if(g[g1]==g[g2]&&f2){
		cout<<1;
		f3=1;
	}
	else cout<<0;
	
	//第四种// 
	map<string,int>l;
	l["A"]=1;
	l["B"]=2;
	l["C"]=3;
	l["D"]=4;
	l["F"]=5;
	string l1=s1.substr(2);
	string l2=s2.substr(2);
	if(l[l1]+1==l[l2]||l[l1]-1==l[l2]){
		if(f3)cout<<1;
		else cout<<0;
		return 0;
	}
	
	cout<<0;
	
	return 0;
}
