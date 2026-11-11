#include<bits/stdc++.h>
using namespace std;

string c,s,cc,ss;
bool check(char a,char b){
	if(a == 'A' && b == 'B')return 1;
	else if(a == 'B'){
		if(b == 'A' || b == 'C')return 1;
	}else if(a == 'C' && b == 'B')return 1;
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>s>>cc>>ss;
	if(c == cc){
		cout<<1;
		if(s[0] == ss[0] && s[1] == ss[1]){
			cout<<1;
			if(s[2] >= 'A' && s[2] <= 'C' && ss[2] >= 'A' && ss[2] <= 'C' || s[2] >= 'D' && s[2] <= 'F' && ss[2] >= 'D' && ss[2] <= 'F'){
				cout<<1;
				if(s[2] >= 'D' && s[2] <= 'F' && ss[2] >= 'D' && ss[2] <= 'F')cout<<1<<'\n';
				else if(check(s[2],ss[2]))cout<<1<<'\n';
				else cout<<"0"<<'\n';
			}
			else cout<<"00"<<'\n';
		}else cout<<"000"<<'\n';
	}
	else cout<<"0000"<<'\n';
	return 0;
}
