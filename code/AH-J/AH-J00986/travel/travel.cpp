#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	bool bb=1;
	if(a==b) cout<<1;
	else cout<<0,bb=0;
	int tc=(c[0]-'0')*10+(c[1]-'0'),td=(d[0]-'0')*10+(d[1]-'0');
	if( bb && tc==td) cout<<1;
	else cout<<0,bb=0;
	if( bb && ( ( c[2]-'A'+1<=3 && d[2]-'A'+1<=3 ) || (c[2]-'A'+1>3&&d[2]-'A'+1>3 ) ) ) cout<<1;
	else cout<<0,bb=0;
	if( bb && abs((c[2]-'A'+1)-(d[2]-'A'+1))==1 ) cout<<1;
	else cout<<0;
	return 0;
}
