#include<bits/stdc++.h>
using namespace std;
int t1,c1,t2,c2;
char x1,x2,x3;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x1>>x2;
	if(x1!='0') t1+=10;
	t1+=(int)(x2-'0');
	
	cin>>x1>>x2>>x3;
	if(x1!='0') c1+=10;
	c1+=(int)(x2-'0');
	s1=x3;
	
	cin>>x1>>x2;
	if(x1!='0') t2+=10;
	t2+=(int)(x2-'0');
	
	cin>>x1>>x2>>x3;
	if(x1!='0') c2+=10;
	c2+=(int)(x2-'0');
	s2=x3;
	
	if(t1!=t2){
		cout<<0<<' '<<0<<' '<<0<<' '<<0;
		return 0;	
	}
	cout<<1<<' ';
	if(c1!=c2){
		cout<<0<<' '<<0<<' '<<0;
		return 0;
	}
	cout<<1<<' ';
	if((s1=='D' && s2=='F') || (s1=='F' && s2=='D')){
		cout<<1<<' '<<1;
		return 0;
	}
	if((s1=='A' && s2=='C') || (s1=='C' && s2=='A')){
		cout<<1<<' '<<0;
		return 0;
	}
	if((s1=='A' && s2=='B') || (s1=='B' && s2=='A') || (s1=='B' && s2=='C') || (s1=='C' && s2=='B')){
		cout<<1<<' '<<1;
		return 0; 
	}
	cout<<0<<' '<<0;
	return 0;
}
