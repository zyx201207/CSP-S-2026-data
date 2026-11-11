#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,id2;
	char x;
}a,b;
bool c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a.id>>a.id2>>a.x;
	cin>>b.id>>b.id2>>b.x;
	if(a.id==b.id)c1=1,cout<<1;
	else cout<<0;
	if(c1&&a.id2==b.id2)c2=1,cout<<1;
	else cout<<0;
	if(c1&&c2&&((a.x<='C'&&b.x<='C')||(a.x>'C'&&a.x<='E'&&b.x>'C'&&b.x<='E')))c3=1,cout<<1;
	else cout<<0;
	if(c1&&c2&&c3&&abs((int)a.x-(int)b.x)==1)cout<<1;
	else cout<<0;
	return 0;
} 
