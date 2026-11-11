//GZ-J00540 顾浩扬 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string a;
int n=0,m=0,x=0,y=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,a);
	if(a[0]==a[7]&&a[1]==a[8]) n=1;
	if(a[3]==a[10]&&a[4]==a[11]&&n) m=1;
	if(('C'>=a[5]&&'C'>=a[12]||'D'<=a[5]&&'D'<=a[12])&&m) x=1;
	if('C'>=a[5]&&(a[5]-a[12]==1||a[12]-a[5]==1)||'D'<=a[5]&&(a[5]-a[12]==2||a[12]-a[5]==2)&&x) y=1;
	cout<<n<<m<<x<<y;
	
	return 0;
} 
