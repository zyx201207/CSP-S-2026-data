#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b,c,d;
ll cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		cnt++;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			cnt++;
			ll x=b[2]-'A',y=d[2]-'A';
			if((x<=2&&y<=2)||(x>2&&y>2)){
				cout<<"1";
				cnt++;
				if(abs(x-y)==1){
					cout<<"1";
					cnt++;
				}
			}
		}
	}
	for(ll i=cnt+1;i<=4;i++)cout<<"0";
	return 0;
}