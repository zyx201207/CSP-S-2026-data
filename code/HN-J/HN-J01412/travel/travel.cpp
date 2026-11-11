#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f1=1,f2=1,f3=1,f4=1;
void init();
void work();
void print();
void init(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
}
void work(){
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			f1=0; f2=0;
			f3=0; f4=0;
			break;
		}
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			f2=0; f3=0;
			f4=0;
			break;
		} 
	}
	char a=s1[2],b=s2[2];
	int q=1;
	if(a<='C'&&a>='A'&&b>='A'&&b<='C'||a>='D'&&a<='F'&&b>='D'&&b<='F') q=0;
	else{
		f3=0; f4=0;
	}
	if(int(a-b)!=1||int(b-a)!=1) f4=0;
}
void print(){
	cout<<f1<<f2<<f3<<f4;
}
int main(){
	init();
	work();
	print();
	return 0;
} 
