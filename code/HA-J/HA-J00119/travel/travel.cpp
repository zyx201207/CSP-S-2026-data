#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c)
		cout<<1;
	else
		cout<<0;
	if(a==c&&(b[0]==d[0]&&b[1]==d[1]))
		cout<<1;
	else
		cout<<0;
	bool iff=0;
	if(b[2]=='D'||b[2]=='F') iff=1;
	bool ifff=0;
	if(d[2]=='D'||d[2]=='F') ifff=1;
	if(a==c&&(b[0]==d[0]&&b[1]==d[1])&&iff==ifff)
		cout<<1;
	else
		cout<<0;
	if(a==c&&(b[0]==d[0]&&b[1]==d[1])&&iff==ifff&&(b[2]-1==d[2]||b[2]+1==d[2]))
		cout<<1;
	else
		cout<<0;
	return 0;
}
