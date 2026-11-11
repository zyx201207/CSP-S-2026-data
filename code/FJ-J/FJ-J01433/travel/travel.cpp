#include<bits/stdc++.h>
#define ll long long
#define FR(a,b,c) for(ll a=b;a<=c;++a)
#define RF(a,b,c) for(ll a=b;a>=c;--a)
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			int x=0,y=0;
			if(b[2]=='A'||b[2]=='B'||b[2]=='C')x=1;
			if(d[2]=='A'||d[2]=='B'||d[2]=='C')y=1;
			if(x==y){
				cout<<1;
				if(x==0&&b[2]+d[2]=='D'+'F'){
					cout<<1;
				}else if(x==1&&(b[2]+d[2]=='A'+'B'||b[2]+d[2]=='C'+'B')){
					cout<<1;
				}else cout<<0;
			}else{
				cout<<"00";
			}
		}else cout<<"000";
	}else{
		cout<<"0000";
	}
	return 0;
}
