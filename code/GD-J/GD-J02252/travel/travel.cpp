#include <bits/stdc++.h>
using namespace std;
char a[3],b[5],c[3],d[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[0]>>a[1];
	cin>>b[0]>>b[1]>>b[2];
	cin>>c[0]>>c[1];
	cin>>d[0]>>d[1]>>d[2];
	if (a[0]==c[0] && a[1]==c[1]){
		cout<<1;
	}
	else cout<<0;
	if ((a[0]==c[0] && a[1]==c[1]) && b[0]==d[0] && b[1]==d[1]){
		cout<<1;
	}
	else cout<<0;
	if ((a[0]==c[0] && a[1]==c[1]) && b[0]==d[0] && b[1]==d[1] && ((b[2]<='C' && d[2]<='C') || (b[2]>='D' && d[2]>='D'))){
		cout<<1;

	}
	else cout<<0;
	if (b[0]==d[0] && b[1]==d[1] && ((b[2]<='C' && d[2]<='C') || (b[2]>='D' && d[2]>='D')) && (b[2]+1==d[2] || b[2]-1==d[2])){
		
		cout<<1;

	}
	else cout<<0;
	return 0;
}
