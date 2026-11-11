#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
bool a,d,f;
int main(){
	freopen("travel4.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c==c1) {
		cout<<1;
		f=1;
	}
	else cout<<0;
	if(s[0]==s1[0] and f==1){
		cout<<1;
		a=1;
	}
	else cout<<0;
	if(((s[1]<='c' and s1[1]<='c') or ((s[1]>'c' and s[1]<='f') and(s1[1]>'c' and s1[1]<='f')))and a==1){
		cout<<1;
		d=1;
	}
	else cout<<0;
	if((s[1]==s1[1]-1 or s[1]+1==s1[1]+1) and d==1) cout<<1;
	else cout<<0;
	return 0;
}
