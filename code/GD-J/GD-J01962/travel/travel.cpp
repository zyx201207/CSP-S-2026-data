#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if(('A'<=b[2]&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||('D'<=b[2]&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')){
				char e=b[2],f=d[2];
				if(e>f) swap(e,f);
				if((e=='A'&&f=='B')||(e=='B'&&f=='C')||(e=='D'&&f=='F')) cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
} 
