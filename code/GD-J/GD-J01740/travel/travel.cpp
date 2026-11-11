#include<bits/stdc++.h>
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define x first
#define y second
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
signed main(){
	fre("travel");
	int a,b;string s,t;
	cin>>a>>s>>b>>t;
	if(a==b){
		cout<<1;
		if(s.substr(0,2)==t.substr(0,2)){
			cout<<1;
			char x=s[2],y=t[2];
			if(x>y) swap(x,y);
			if((x<'D')==(y<'D')){
				cout<<1;
				if(abs(x-y)==1||(x=='D'&&y=='F')) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}else cout<<"0000";
}

