#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	string n,m,s1,s2;
	cin>>n>>s1>>m>>s2;
	bool f=0,p=0;
	if(n==m) cout<<1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
			f=1;
			if(s1[2]-s2[2]==1||s2[2]-s1[2]==1||(s1[2]=='F'&&s2[2]=='D')||(s2[2]=='F'&&s1[2]=='D'))
			p=1;
		}
	}
	else cout<<0;
	if(f)cout<<1;
	else cout<<0;
	if(p) cout<<1;
	else cout<<0;
	return 0;
}
