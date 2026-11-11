#include<iostream> 
using namespace std;
char c1[2],s1[3],c2[2],s2[3];
int b=1;
int main(){
	cin>>c1>>s1>>c2>>s2;
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);
	
	if(c1==c2){
		cout<<b;
	}
	else{
		b=0;
		cout<<b;
	}
	
	b=1;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			b=0;
		}
		
	}
	cout<<b;
	if((int(s1[2])<=67 && int(s2[2])<=67) || (int(s1[2])>67 && int(s2[2])>67)){
		b=1;
		if(s1[2]=='D' ||s2[2]=='D'){
			cout<<b;
		}
		if(s1[2]=='B' ||s2[2]=='B'){
		cout<<1;
	}
	}
	else{
		b=0;
		cout<<b;
	}
	cout<<b;
	
	return 0;
}
