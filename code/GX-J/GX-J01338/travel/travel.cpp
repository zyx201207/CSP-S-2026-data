#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a1,b1;
	string a2,b2;
	cin>>a1>>a2>>b1>>b2;//cout<<a2[2]<<' '<<a2[2]-'A'<<' '<<b2[2]-'A'<<' ';
	if(a1==b1){cout<<1;}
	else cout<<0;
	//if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1])cout<<1;else cout<<0;
	if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]){cout<<1;
		if((a2[2]-'A'<=2&&b2[2]-'A'<=2)||(a2[2]-'A'>2&&b2[2]-'A'>2)){
			cout<<1;
			if((a2[2]-'A')+(b2[2]-'A')==2)
			cout<<0;
			else cout<<1;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	return 0;
	
}
