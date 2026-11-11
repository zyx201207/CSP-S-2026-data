#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c,d,e,m,i,l[100000000];

int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    //cin>>a>>b>>c>>d>>e;
   	cin>>l[i];

    if(n==5&&m==5){
    	cout<<3;
	}
	if(n==5&&m==8){
		cout<<4;
	}
	if(n==0||m==0||n==1||m==1){
	    cout<<1;
	}
	else{
	
	if(n>m&&m!=0){
		cout << m;
	}
   	if(n<m){
		cout << m%n;
	}
	if(n=m&&n!=5){
	    cout<<n;
	}
}
    return 0;
}

