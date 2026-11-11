#include<bits/stdc++.h>
using namespace std;
char a[100000],b[100000];
int a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a>>b1>>b;
		if(a1==b1) cout<<"1";
		else cout<<0; 
		if(a[0]==b[0]&&a[1]==b[1]) cout<<"1";
		else cout<<0; 
	    if((a[0]==b[0]&&a[1]==b[1])&&((a[2]<='c'&&b[2]<='c')||(a[2]>'c'&&b[2]>'c'))) cout<<"1";
	    else cout<<0; 
		if((a[0]==b[0]&&a[1]==b[1])&&((a[2]<='c'&&b[2]<='c')||(a[2]>'c'&&b[2]>'c'))&&(a[2]-b[2]==1||b[2]-a[2]==1)) cout<<"1";
		else cout<<0; 
	return 0;
}
