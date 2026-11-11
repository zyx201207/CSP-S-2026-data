#include <bits/stdc++.h>
using namespace std;
string r,r1,x,x1;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>r1>>x>>x1;
	int a=r1[2]-x1[2];
	if(r!=x)
		cout<<"0000";
	else if(r1[0]!=x1[0]||r1[1]!=x1[1])
		cout<<"1000";
	else if(r1[2]>'C'&&x1[2]<='C'||r1[2]<='C'&&x1[2]>'C')
		cout<<"1100";
	else if(a>1||a<-1)
		cout<<"1110";
	else
		cout<<"1111";
	return 0;
}
