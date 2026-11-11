#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	string n,m,a,b;
	bool c1,c2,c3,c4;
	cin>>n>>a>>m>>b;
	if(n==m){
		c1=1;
		if(a[0]==b[0] && a[1]==b[1]){
			c2=1;
			if((a[2]<='C' && b[2]<='C') || (a[2]>'C' && b[2]>'C')){
				c3=1;
				if(a[2]-1==b[2] || a[2]+1==b[2]){
					c4=1;
				}
			}
		}
	}
	cout<<c1<<c2<<c3<<c4;
	return 0;
	fclose("stdin");
	fclose("stdout");
}

