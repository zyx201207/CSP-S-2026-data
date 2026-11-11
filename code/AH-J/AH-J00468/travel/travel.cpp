#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char a1,b1;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
scanf("%2d %2d%c %2d %2d%c",&a,&b,&a1,&c,&d,&b1);
if(a==c){
	cout<<'1';
	if(b==d){
	cout<<'1';
	if(('A'<=a1 && a1<='C' && 'A'<=b1 && b1<='C')||('C'<=a1 && a1<='D' && 'C'<=b1 && b1<='C')){
		cout<<'1';
		if(int(fabs(a1-b1))==1)cout<<1<<" ";
		else cout<<'0';
	}else cout<<"00";
}else cout<<"000";
}else cout<<"0000";
return 0;
}
