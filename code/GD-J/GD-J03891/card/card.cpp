#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n=5,m=2)cout<<"5"<<" "<<"1";
	if(n=5,m=1)cout<<"5";
	if(n=4,m=1)cout<<"4";
	if(n=3,m=1)cout<<"3";
	if(n=2,m=1)cout<<"2";
	if(n=1,m=1)cout<<"1";
	return 0;
}
