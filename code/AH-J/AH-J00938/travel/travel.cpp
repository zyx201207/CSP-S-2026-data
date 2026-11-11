#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,c;
string b,d;
bool cheak(char c1,char c2){
	if(c1-'A'>2&&c2-'A'>2) return 1;
	else if(c1-'A'<3&&c2-'A'<3) return 1;
	else return 0;
}
bool cheak1(char n,char m){
	if(m-'A'>2&&n-'A'>2) return 1;
	else if(m-'A'<3&&n-'A'<3 &&m!=n-2&&n!=m-2) return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1] && a==c) cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1] && a==c && cheak(b[2],d[2]))
		cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1] && a==c && cheak(b[2],d[2]) && cheak1(b[2],d[2]))
		cout<<1;
	else cout<<0;
	return 0;
}
