#include<bits/stdc++.h>
using namespace std;
char a[3],b[3];
string x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a[0] >> a[1] >> x;
	cin >> b[0] >> b[1] >> y;
	if((a[0]!=b[0])||(a[1]!=b[1]))
		cout << "0000";
	else if((x[0]!=y[0])||(x[1]!=y[1]))
		cout << "1000";
	else if(((x[2]>='A'&&x[2]<='C')&&(y[2]>='D'&&y[2]<='F'))||((x[2]>='D'&&x[2]<='F')&&(y[2]>='A'&&y[2]<='C')))
		cout << "1100";
	else if(((x[2]=='D'&&y[2]=='F')||(x[2]=='F'&&y[2]=='D'))||abs(x[2]-y[2])==1)
		cout << "1111";
	else cout << "1110";
	return 0;
}
