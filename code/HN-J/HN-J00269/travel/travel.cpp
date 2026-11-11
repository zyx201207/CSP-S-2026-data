#include<bits/stdc++.h>
using namespace std;
int a,x,b,y,f=1;
char l,r,z;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>z>>a>>z>>x>>l>>z>>b>>z>>y>>r;
	int k=bool(a==b);
	cout<<k;
	cout<<bool(x==y&&k);
	if(x==y&&k){
		if(l<='C'&&r<='C')f=1;
		else if('D'<=l&&'D'<=r)f=1;
		else f=0;
	}
	else f=0;
	cout<<f<<bool(k&&abs(l-r)==1&&f);
	return 0;
}
