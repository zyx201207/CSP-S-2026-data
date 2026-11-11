#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	char r1,r2;
	for(int i=0;i<2;i++){
		r1=r1+s1[i];
		r2=r2+s2[i];
	}
	if(r1==r2 && c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	char t1=s1.back(),t2=s2.back();
	if(((t1=='A'&&t2=='B')||(t1=='A'&&t2=='C')
	||(t1=='B'&&t2=='C')||(t1=='B'&&t2=='A')
	||(t1=='C'&&t2=='A')||(t1=='C'&&t2=='B')
	||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D'))&& r1==r2 && c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(((t1=='A'&&t2=='B')||(t1=='B'&&t2=='C')
	||(t1=='C'&&t2=='B')||(t1=='B'&&t2=='A')
	||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D')) && r1==r2 && c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0; 
} 
