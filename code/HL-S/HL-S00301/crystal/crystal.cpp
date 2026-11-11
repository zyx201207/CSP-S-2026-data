#include<bits/stdc++.h>
using namespace std;
int main(){

	char a[5],b,c;
    cin>>c>>b;
    cin>>a;
    if(a[1]<a[2]<a[3]<a[4]<a[5]){
    	a[1]+1;
    	b-1;
	}if(b=0,a[1]!=a[2],a[1]!=a[3],a[1]!=a[4],a[1]!=a[5])
		cout<<"1";
	if(b=0,a[1]==a[2]||a[1]==a[3]||a[1]==a[4]||a[1]==a[5]||a[2]==a[3]||a[2]==a[4]||a[3]==a[5]||a[4]==a[5])
		cout<<"2";
	if(b=0,a[1]==a[2]==a[3]||a[1]==a[2]==a[4]||a[1]==a[2]==a[5]||a[5]==a[2]==a[3]||a[5]==a[4]==a[3])
		cout<<"3";
	if(b=0,a[1]==a[2]==a[3]==a[4]||a[2]==a[3]==a[4]==a[5])
	 
	if(b=0,a[1]==a[2]==a[3]==a[4]==a[5])
		cout<<"5";
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
     return 0;	}
