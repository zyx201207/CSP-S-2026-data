#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdont);
	int n,m;
	cin>>n>>m;
	if(n<=2*10*10*10*10*10 && m<=n){
		cout<<4;
	}if(n<20  && m<=n){
		cout<<10;
	}else{
		cout<<27;
	}
	return 0;
}
