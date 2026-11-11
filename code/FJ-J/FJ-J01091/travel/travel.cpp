#include<bits/stdc++.h>
using namespace std;
#define int long long
bool a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,nn,m,mm;
	cin>>n>>m>>nn>>mm;
	if(n==nn)a=1;
	if(m[0]==mm[0]&&m[1]==mm[1]&&a==1)b=1;
	if(((m[2]>'C'&&mm[2]>'C')||(mm[2]<'C'&&m[2]<'D'))&&b==1&&a==1)c=1;
	if(m[0]==mm[0]&&m[1]==mm[1]&&c==1&&a==1&&b==1){
		if((m[2]+1==mm[2])||(mm[2]+1==m[2])&&c==1&&a==1&&b==1)d=1;
	}
	cout<<a<<b<<c<<d;
}
