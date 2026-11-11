#include <bits/stdc++.h>
using namespace std;
struct{
	long long a,b;
	char acx,ap,ac,azy;
	char bcx,bp,bc,bzy;
}xx[10005];
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a,b;
	char acx,ap,ac,azy;
	char bcx,bp,bc,bzy;
	if(a==a||b==b){
	if(acx!=bcx) cout<<"0";
	else if(acx==bcx) cout<<"1";
	
	if(acx==bcx&&ap!=bp) cout<<"0";	
	else if(acx==bcx&&ap==bp) cout<<"1";
	if(acx!=bcx&&ap!=bp) cout<<"0";
	else if(acx!=bcx&&ap==bp) cout<<"1";
	
	if(acx==bcx&&ap!=bp&&ac!=bc) cout<<"0";
	else if(acx==bcx&&ap!=bp&&ac==bc) cout<<"1";
	if(acx==bcx&&ap==bp&&ac!=bc) cout<<"0";
	else if(acx==bcx&&ap==bp&&ac==bc) cout<<"1";
	if(acx!=bcx&&ap!=bp&&ac!=bc) cout<<"0";
	else if(acx!=bcx&&ap!=bp&&ac==bc) cout<<"1";
	if(acx!=bcx&&ap==bp&&ac!=bc) cout<<"0";
	else if(acx!=bcx&&ap==bp&&ac==bc) cout<<"1";
	
	if(acx==bcx&&ap!=bp&&ac!=bc&&azy!=bzy) cout<<"0";
	else if(acx==bcx&&ap!=bp&&ac==bc&&azy==bzy) cout<<"1";
	if(acx==bcx&&ap==bp&&ac!=bc&&azy!=bzy) cout<<"0";
	else if(acx==bcx&&ap==bp&&ac==bc&&azy==bzy) cout<<"1";
	if(acx==bcx&&ap!=bp&&ac!=bc&&azy==bzy) cout<<"0";
	else if(acx==bcx&&ap!=bp&&ac==bc&&azy!=bzy) cout<<"1";
	if(acx==bcx&&ap==bp&&ac!=bc&&azy==bzy) cout<<"0";
	else if(acx==bcx&&ap==bp&&ac==bc&&azy!=bzy) cout<<"1";
	if(acx!=bcx&&ap!=bp&&ac!=bc&&azy!=bzy) cout<<"0";
	else if(acx!=bcx&&ap!=bp&&ac==bc&&azy==bzy) cout<<"1";
	if(acx!=bcx&&ap==bp&&ac!=bc&&azy!=bzy) cout<<"0";
	else if(acx!=bcx&&ap==bp&&ac==bc&&azy==bzy) cout<<"1";
	if(acx!=bcx&&ap!=bp&&ac!=bc&&azy==bzy) cout<<"0";
	else if(acx!=bcx&&ap!=bp&&ac==bc&&azy!=bzy) cout<<"1";
	if(acx!=bcx&&ap==bp&&ac!=bc&&azy==bzy) cout<<"0";
	else if(acx!=bcx&&ap==bp&&ac==bc&&azy!=bzy) cout<<"1";
	}
	else cout<<"0000";
	return 0;
} 

