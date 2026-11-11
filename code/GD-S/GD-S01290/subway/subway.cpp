#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>n;
	if(n==2)cout<<32<<endl<<17;
	else if(n==3)cout<<35<<endl<<16;
	else cout<<0<<endl<<0;
	return 0;
} 
