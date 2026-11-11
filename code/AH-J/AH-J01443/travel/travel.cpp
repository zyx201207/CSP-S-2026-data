#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char x1,x2;
	cin>>c1>>s1>>x1>>c2>>s2>>x2;
	if(x1>x2) swap(x1,x2);
	if(c1!=c2) cout<<"0000";else{
	cout<<1;
	if(s1!=s2) cout<<"000";else{
	cout<<1;
	if(x2>='D' && x1<='C') cout<<"00";else{
	cout<<1;
	if(x2<'D' && x1==x2-1) cout<<1;
	else if(x1>='D') cout<<1;
	else cout<<0;}}}
	return 0;
}
// J01443 OrangeSheep
