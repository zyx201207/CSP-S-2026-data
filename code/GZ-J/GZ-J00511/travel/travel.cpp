//GZ-J00511 张俊熙 兴义市弘毅中学 
#include<iostream>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
char a[2],b[3],c[2],d[3],k,j;
char q[6]="ABCDE";
bool g=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[1]==c[1]&&a[0]==c[0]) cout<<1;
	else {
		cout<<0;
		g=false;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&g) cout<<1;
	else {
		cout<<0;
		g=false;
	}
	k=max(b[2],d[2]),j=min(b[2],d[2]);
	if(k!='D'&&j!='C'&&g) {
		cout<<1;
	}
	else {
		cout<<0;g=false;
	}
	if(k-j==1&&g) cout<<1;
	else cout<<0;
	return 0;
}
