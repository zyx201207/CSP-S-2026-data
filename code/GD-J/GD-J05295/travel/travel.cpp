#include<bits/stdc++.h>
using namespace std;
char r,x;
string cx,sx,cr,sr;
bool a,b,c,d;
int cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx) a=1;
	else{
		cout<<"0000";
		return 0;
	} 
	for(int i=0;i<sr.size();i++){
		if(sr[i]==sx[i]&&'0'<=sr[i]<='9'&&'0'<=sx[i]<='9') cnt++; 
		if('A'<=sr[i]<='F') r=sr[i];
		if('A'<=sx[i]<='F') x=sx[i];
	}
	if(cnt==2) b=1;
	else{
		cout<<"1000";
		return 0;
	}
	if(r<='C'){
		if(x<='C'){
			cout<<2<<endl;
			c=1;
		}
	}
	else if(('D'<=r<='F')&&('D'<=x<='F')){
		c=1;	
	}
	else{
		cout<<"1100";
		return 0;
	}
	if(c==1&&abs(r-x)==1){
		d=1;
	}
	cout<<"111"<<d;
	return 0;
}
