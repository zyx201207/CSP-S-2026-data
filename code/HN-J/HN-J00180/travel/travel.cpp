#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long

string c1,s1,c2,s2;

void solve(){
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2],b=s2[2];
	bool x=(a<='C'),y=(b<='C');
	int p=a-'A',q=b-'A';
	bool f1=(c1==c2);
	bool f2=(s1.substr(0,2)==s2.substr(0,2));
	bool f3=(x==y);
	bool f4=(abs(p-q)==1);
	cout<<f1;
	cout<<(f1 && f2);
	cout<<(f1 && f2 && f3);
	cout<<(f1 && f2 && f3 && f4);
	return ;
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}

