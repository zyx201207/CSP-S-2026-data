#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	int a,b;
	string h,l;
	cin>>a>>h>>b>>l;
	if(a != b){ cout<<"0000";return 0;}
	cout<<'1';
	if(h[1]!=l[1] || h[0]!=l[0]){ cout<<"000";return 0;}
	cout<<"1";
	if(((l[2]!='A' && l[2]!='B' && l[2]!='C') && h[2]<'D') || ((h[2]!='A' && h[2]!='B' && h[2]!='C') && l[2]<'D')){ cout<<"00";return 0;}
	cout<<'1';
	if((h[2]+1 != l[2] && h[2]-1 != l[2]) || (h[2]+2 != l[2] || h[2]-2 != l[2])){ cout<<"0";return 0;}
	cout<<'1';
	return 0;
}

