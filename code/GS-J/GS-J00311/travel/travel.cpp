#include<iostream>
using namespace std;
char s1[100];
char s2[100];
char c1[100];
char c2[100];
char A[100]={'A','B','C','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		a=1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			b=1;
			
			if((s1[2]==A[0] || s1[2]==A[1] || s1[2]==A[2]) && (s2[2]==A[3] || s2[2]==A[4])){
				c=0;
				d=0;
			}
			else if((s2[2]==A[0] || s2[2]==A[1] || s2[2]==A[2]) && (s1[2]==A[3] || s1[2]==A[4])){
				c=0;
				d=0;
			}
			else{
				c=1;
				if(s1[2]==A[0] && s2[2]==A[3]){
					d=0;
				}
				else if(s1[2]==A[0] && s2[2]==A[4]){
					d=0;
				}
				else if(s1[2]==A[0] && s2[2]==A[2]){
					d=0;
				}
				else if(s1[2]==A[1] && s2[2]==A[3]){
					d=0;
				}
				else if(s1[2]==A[1] && s2[2]==A[4]){
					d=0;
				}
				else if(s1[2]==A[1] && s2[2]==A[2]){
					d=0;
				}
				else if(s1[2]==A[2] && s2[2]==A[3]){
					d=0;
				}
				else if(s1[2]==A[2] && s2[2]==A[4])
				{
					d=0;
				}
				else if(s1[2]==A[2] && s2[2]==A[2])
				{
					d=0;
				}
				else if(s2[2]==A[0] && s1[2]==A[3]){
					d=0;
				}
				else if(s2[2]==A[0] && s1[2]==A[4]){
					d=0;
				}
				else if(s2[2]==A[0] && s1[2]==A[2]){
					d=0;
				}
				else if(s2[2]==A[1] && s1[2]==A[3]){
					d=0;
				}
				else if(s2[2]==A[1] && s1[2]==A[4]){
					d=0;
				}
				else if(s2[2]==A[1] && s1[2]==A[2]){
					d=0;
				}
				else if(s2[2]==A[2] && s1[2]==A[3]){
					d=0;
				}
				else if(s2[2]==A[2] && s1[2]==A[4])
				{
					d=0;
				}
				else if(s2[2]==A[2] && s1[2]==A[2])
				{
					d=0;
				}
				else{
					d=1;
				}
			}
		}
		else{
			b=0;
			c=0;
			d=0;
		}
	}
	else{
		a=0;
		b=0;
		c=0;
		d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
