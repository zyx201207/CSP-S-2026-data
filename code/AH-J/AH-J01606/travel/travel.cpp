#include<bits/stdc++.h>
using namespace std;
long long r1,x1;
string r2,x2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	cout<<(r1==x1?1:0);
	cout<<(r1==x1&&(r2[0]==x2[0]&&r2[1]==x2[1])?1:0);
	cout<<(r1==x1&&r2[0]==x2[0]&&r2[1]==x2[1] &&(r2[2]<='C'&&x2[2]<='C' || r2[2]>='D'&&x2[2]>='D')?1:0);
	cout<<((abs(r2[2]-x2[2])==1)&&(r1==x1&&r2[0]==x2[0]&&r2[1]==x2[1] &&(r2[2]<='C'&&x2[2]<='C' || r2[2]>='D'&&x2[2]>='D'))?1:0);
	return 0;
} 
