#include<bits/stdc++.h>
using namespace std;
string a,a2,b,b2;
int main(){
	freopen("freopen.travel","r","travel.in");
	freopen("freopen.travel","w","travel.out");
	cin>>a>>a2>>b>>b2;
	if(a[0]==b[0]&&a[1]==b[1]){
	    cout<<1;
    }
    else {cout<<0<<0<<0<<0;return 0;}
    if(a2[0]==b2[0]&&a2[1]==b2[1])cout<<1;
    else{
    	cout<<0<<0<<0;
    	return 0;
    }
    if((a2[2]=='C'&&b2[2]=='D')||(a2[2]=='D'&&b2[2]=='C')){
	    cout<<0<<0;
	    return 0;
    }
	else cout<<1<<" ";
    if(a2[2]-b2[2]==1||a2[2]-b2[2]==-1)cout<<1;
    else cout<<0;
    return 0;
}
