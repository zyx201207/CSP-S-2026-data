#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	char a[10],b[10],c[10],d[10];
	cin>>a[1]>>a[2]>>b[1]>>b[2]>>b[3]>>c[1]>>c[2]>>d[1]>>d[2]>>d[3];
	ll sc=(a[1]-'0')*10+a[2]-'0',sz=(b[1]-'0')*10+b[2]-'0';
	ll xc=(c[1]-'0')*10+c[2]-'0',xz=(d[1]-'0')*10+d[2]-'0';
	if(sc==xc){
		cout<<1;
		if(sz==xz){
			cout<<1;
			if((b[3]<'D'&&d[3]<'D')||(b[3]>'C'&&d[3]>'C')){
				cout<<1;
				if((b[3]=='A'&&d[3]=='C')||(d[3]=='A'&&b[3]=='C'))cout<<0;
				else cout<<1;
			}
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}