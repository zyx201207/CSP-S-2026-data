#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a;
	cin>>a;
	string c;
	cin>>c;
	int b;
	cin>>b;
	string d;
	cin>>d;
	if(a==b) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	if(c[0]==d[0] and c[1]==d[1]) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(c[2]>='D' and d[2]>='D') cout<<1;
	else if(c[2]<'D' and d[2]<'D') cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	
	if(abs(c[2]-d[2])==1) cout<<1;
	else cout<<0;
 	return 0;
}
