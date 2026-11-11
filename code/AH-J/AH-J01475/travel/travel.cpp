#include<bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,a1,b,b1;
	char a2,b2;
	cin>>a>>a1>>a2>>b>>b1>>b2;
	a2=a2-'A';
	b2=b2-'A';	
	if(a==b){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==b&&a1==b1){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==b&&a1==b1&&((a2<=2&&b2<=2)||(a2>2&&b2>2))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a==b&&a1==b1&&((a2<=2&&b2<=2)||(a2>2&&b2>2))&&abs(a2-b2)==1){
		cout<<1;
	}else{
		cout<<0;
	}

	return 0;
}
