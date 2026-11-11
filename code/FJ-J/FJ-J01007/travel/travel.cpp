#include<iostream>
#include<cstdio>
#include<string>
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::string c1,s1,c2,s2;
	std::cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		std::cout<<"0000";
		return 0;
	}
	std::cout<<1;
	std::string t1,t2;
	t1=s1[0]+s1[1];
	t2=s2[0]+s2[1];
	if(t1!=t2){
		std::cout<<"000";
		return 0;
	}
	std::cout<<1;
	int a=s1[2];
	int b=s2[2];
	int t[1000];
	t['A']=1;	
	t['B']=1;	
	t['C']=1;	
	t['D']=2;	
	t['F']=2;
	//std::cout<<a<<' '<<b<<'\n';
	if(t[a]!=t[b]){
		std::cout<<"00";
		return 0;
	}
	std::cout<<1;
	if(a>b){
		int t=a;
		a=b;
		b=t;
	}
	if(b=='F'||(a=='A'&&b=='B')||(a=='B'&&b=='C')) std::cout<<1;
	else std::cout<<0;
	return 0;
}
