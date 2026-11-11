#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]!=c[0]||a[1]!=c[1])cout<<"0000"<<'\n';
	else if(b[0]!=d[0]||b[1]!=d[1])cout<<"1000"<<'\n';
	else{
		int ans=abs(b[2]-d[2]);
		if((b[2]<='C'&&d[2]>='D')||(b[2]>='D'&&d[2]<='C'))cout<<"1100"<<'\n';
		else if(ans>1)cout<<"1110"<<'\n';
		else cout<<"1111"<<'\n';
	}
	return 0;
}
