//GZ-J00125 习水县第七中学 李卓巾 

#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int r1,x1;
	string r2,x2;
	cin>>r1>>r2>>x1>>x2;
	
	bool b1,b2,b3,b4;
	if(r1==x1)b1=1;
	else b1=0;
	if(r2[0]==x2[0]&&r2[1]==x2[1])b2=1;
	else b2=0;
	
	if(((r2[2]=='A'||r2[2]=='B'||r2[2]=='C')&&(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'))||
		((r2[2]=='D'||r2[2]=='F')&&(x2[2]=='D'||x2[2]=='F')))b3=1;
	else b3=0;
	
	if(((r2[2]=='D'&&x2[2]=='F')||(r2[2]=='F'&&x2[2]=='D'))||(r2[2]+1==x2[2])||(r2[2]-1==x2[2]))
		b4=1;
	else b4=0;
	
	if(b1)cout<<1;
	else cout<<0;
	if(b1&&b2)cout<<1;
	else cout<<0;
	if(b1&&b2&&b3)cout<<1;
	else cout<<0;
	if(b1&&b2&&b3&&b4)cout<<1;
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
