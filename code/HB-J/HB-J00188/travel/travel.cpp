#include<bits/stdc++.h>
using namespace std;
int x,y,x2,y2,c1,c2;char c11,c22;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>x2>>c11>>y>>y2>>c22;
	cout<<(x==y?1:0);
	cout<<(x==y&&x2==y2?1:0);
	c1=c11,c2=c22;
	if(x==y&&((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C'))&&x2==y2)cout<<1;else cout<<0;
	if(x==y&&((c1<='C'&&c2<='C')||(c1>'C'&&c2>'C'))&&x2==y2&&(abs(c2-c1)==1))cout<<1;else cout<<0;
	return 0;
}
