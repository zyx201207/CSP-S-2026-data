#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
char c[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr[0]==cx[0]&&cr[1]==cx[1])c[1]='1';
	else c[1]='0';
	if(sr[0]==sx[0]&&sr[1]==sx[1]&&c[1]=='1')c[2]='1';
	else c[2]='0';
	if(((sr[2]>='A'&&sr[2]<='C'&&sx[2]>='A'&&sx[2]<='C')||(sr[2]>='D'&&sr[2]<='F'&&sx[2]>='D'&&sx[2]<='F'))&&c[2]=='1')c[3]='1';
	else c[3]='0';
	if(c[2]=='0'||c[3]=='0')c[4]='0';
	else if(abs(sr[2]-sx[2])==1||((sr[2]=='D'&&sx[2]=='F')||(sr[2]=='D'&&sx[2]=='F')))c[4]='1';
	else c[4]='0';
	for(int i=1;i<=4;i++)cout<<c[i];
	return 0;
}
