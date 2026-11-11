#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,s1,c2,s2;
char ch1,ch2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>ch1>>c2>>s2>>ch2;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if(!(ch1<='C')^(ch2<='C')){
				cout<<1;	
				if(abs(ch1-ch2)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

