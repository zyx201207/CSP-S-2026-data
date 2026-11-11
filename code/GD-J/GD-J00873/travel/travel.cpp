#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+5,M=1e2+5;
const int INF=0x3f3f3f3f,MOD=1e9+7;
typedef long long LL;
string a,b,c,d;
int mp[]={1,1,1,2,0,2};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c)cout<<"0000";
	else{
		cout<<"1";
		if(b.substr(0,2)!=d.substr(0,2))cout<<"000";
		else{
			cout<<"1";
			char x=b[2],y=d[2];
			if(mp[x-'A']!=mp[y-'A'])cout<<"00";
			else{
				cout<<"1";
				if((x=='A'&&y=='C')||(x=='C'&&y=='A'))cout<<"0";
				else cout<<"1";
			}
		}
	}
	return 0;
}

