#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,x1;
	char r2[3],x2[3];
	cin>>r1;
	for(int i=0;i<3;i++){
		cin>>r2[i];
	}
	cin>>x1;
	for(int i=0;i<3;i++){
		cin>>x2[i];
	}
	int a=0,b=0,c=0,d=0;
	if(r1==x1){
		a=1;
		if(r2[0]==x2[0]&&r2[1]==x2[1]){
			b=1;
			if('A'<=r2[2]<='C'&&'A'<=x2[2]<='C'||'C'<=r2[2]<='D'&&'C'<=x2[2]<='D'){
				c=1;
				if(r2[2]+1==x2[2]||r2[2]-1==x2[2]){
					d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
