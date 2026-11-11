#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2,t1,t2;
char ch1,ch2;
bool flag=false;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	t1=s1.substr(0,2);
	t2=s2.substr(0,2);
	if(t1==t2){
		cout<<1;
		if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C')){
			cout<<1;
			ch1=s1[2],ch2=s2[2];
			if(abs(ch1-ch2)==1) cout<<1;
			else cout<<0;
		}
		else cout<<"00";
	}
	else cout<<"000";
	return 0;
}
