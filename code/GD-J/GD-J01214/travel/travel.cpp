#include<bits/stdc++.h>
#define int long long 
using namespace std;
string a,a1,b,b1;
signed main(){
	freopen("travel.in" ,"r",stdin );
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a!=b)
		puts("0000");
	else if(a1.substr(0,2)!=b1.substr(0,2))
		puts("1000");
	else if(!((a1[2]<='C'&&b1[2]<='C') || (a1[2]>'C'&&b1[2]>'C')))
		puts("1100");
	else{
		char c1=a1[2],c2=b1[2];
		if(c1<c2)swap(c1,c2);
		//now c1 > c2
		if(c1<='C'){//об╡Ю
			if(c2==c1-1)puts("1111");
			else puts("1110");
		}
		else{//ио╡Ю 
			if(c1=='F'&&c2=='D')puts("1111");
			else puts("1110");
		}
	}
	return 0;
}
