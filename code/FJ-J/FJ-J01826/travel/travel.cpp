#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
	}else{
		a[1]=0;
		a[2]=0;
		a[3]=0;
		a[4]=0;
		for(int i=1;i<=4;i++){
			cout<<a[i];
		}
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[2]=1;
	}else{
		a[2]=0;
		a[3]=0;
		a[4]=0;
		for(int i=1;i<=4;i++){
			cout<<a[i];
		}
		return 0;
	}
	int l=0,r=0;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		l++;
	}else if(s1[2]=='D'||s1[2]=='F'){
		r++;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		l++;
	}else if(s2[2]=='D'||s2[2]=='F'){
		r++;
	}
	if(l==2||r==2){
		a[3]=1;
	}else{
		a[3]=0;
		a[4]=0;
		for(int i=1;i<=4;i++){
			cout<<a[i];
		}
		return 0;
	}
	char e,o;
	e=s1[2];
	o=s2[2];
	if((char)(e+1)==o||(char)(e-1)==o){
		a[4]=1;
	}else{
		a[4]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	return 0;
}
