#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	int x1=10*(s1[0]-'0')+(s1[1]-'0');
	int x2=10*(s2[0]-'0')+(s2[1]-'0');
	int b=0;
	if(x1==x2&&c1==c2){
		b=1;
		cout<<1;
	}else{
		cout<<0;
	}
	char a1=s1[2],a2=s2[2];
	int f=0;
	if(((a1>='D'&&a2>='D')||(a1<='C'&&a2<='C'))&&b==1){
		f=1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(abs(a1-a2)==1&&f==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
