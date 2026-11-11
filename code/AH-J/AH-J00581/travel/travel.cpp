#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	long long x1=0,x2=0,x3=0,x4=0;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		x1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			x2=1;
			if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
				x3=1;
				char n=s1[2],m=s2[2];
				if(n==m+1||n==m-1){
					x4=1;
				}
			}
			if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				x3=1;
				x4=1;
			}
		}
	}
	cout<<x1<<x2<<x3<<x4;
	return 0;
}
