#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
char a[4],b[4],c[4],d[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(strcmp(a,c)!=0){
		cout << "0000";
		return 0;
	}cout << 1;
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout << "000";
		return 0;
	}cout << 1;
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')
		&&(d[2]=='D'||d[2]=='F')||
		(d[2]=='A'||d[2]=='B'||d[2]=='C')
		&&(b[2]=='D'||b[2]=='F')){
		cout << "00";
		return 0;
	}cout << 1;
	if(abs(b[2]-d[2])==1)
		cout << 1;
	else cout << 0;
	cout << endl;
	return 0;
} 
