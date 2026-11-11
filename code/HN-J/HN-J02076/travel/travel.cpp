#include<bits/stdc++.h>
using namespace std;
bool f=1;
char rc[3],rs[4],xc[3],xs[4];
int l1[6][6]={{1,1,1,0,0,0},{1,1,1,0,0,0},{1,1,1,0,0,0},{0,0,0,1,0,1},{0,0,0,0,1,0},{0,0,0,1,0,1}},l2[6][6]={{1,1,0,0,0,0},{1,1,1,0,0,0},{0,1,1,0,0,0},{0,0,0,1,0,1},{0,0,0,0,1,0},{0,0,0,1,0,1}};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(f&&rc[0]==xc[0]&&rc[1]==xc[1])cout<<1;
	else cout<<0,f=0;
	if(f&&rs[0]==xs[0]&&rs[1]==xs[1])cout<<1;
	else cout<<0,f=0;
	if(f&&l1[int(rs[2]-'A')][int(xs[2]-'A')]==1)cout<<1;
	else cout<<0,f=0;
	if(f&&l2[int(rs[2]-'A')][int(xs[2]-'A')]==1)cout<<1;
	else cout<<0,f=0;
	return 0;
}
