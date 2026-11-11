#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(travel.in);
	freopen(travel.out);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int x=b[0]+b[1],y=d[0]+d[1];
	if(a==c)cout<<1;
	else cout<<0;
	if(x==y)cout<<1;
	else cout<<0;
	if(x==y && (('A'<=b[2] && 'A'<=d[2] && 'C'>=b[2] && 'C'>=d[2]) || ('D'<=b[2] && 'D'<=d[2] && 'F'>=b[2] && 'F'>=d[2])))cout<<1;
	else cout<<0;
	if(b[2]==d[2]+1 || b[2]==d[2]-1)cout<<1;
	else cout<<0;
	return 0;
} 
