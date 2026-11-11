#include<bits/stdc++.h>
using namespace std;
int a[20][10];//³µÏá 
int c0,c1;
string s0,s1;
int cx(){
	if(c0==c1)return 1;
	return 0;
}
int tp(int a,int b){
	if(cx()){
		if(a==b)return 1;
	}
	return 0;
}
int tc(int a0,int b0,int a1,int b1){
	if(cx()&&tp(a0,a1)){
		if(b0>4 && b1>4)return 1; 
		else if(b0<4 && b1<4){
			return 1;
		}
	}
	return 0;
}
int xl(int a0,int b0,int a1,int b1){
	if(tp(a0,a1) && tc(a0,b0,a1,b1) && abs(b0-b1)==1){
		return 1;
		}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>c0>>s0>>c1>>s1;
	int x0,y0,x1,y1;
	x0=(s0[0]-'0')*10+s0[1]; x1=(s1[0]-'0')*10+s1[1];
	y0=s0[2]-'A'+1; y1=s1[2]-'A'+1;
	if(s0[2]=='D'||s0[2]=='E')y0++;
	if(s1[2]=='D'||s1[2]=='E')y1++;
	cout<<cx()<<tp(x0,x1)<<tc(x0,y0,x1,y1)<<xl(x0,y0,x1,y1);
} 
