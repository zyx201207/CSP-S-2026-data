#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x=s1[2];
	int y=s2[2];
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	cout<<1;
	if(s1[1]==s2[1]&&s1[0]==s2[0]) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((x-1<='C'-1&&y-1<='C'-1)||(x-1>'C'-1&&y-1>'C'-1)) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if((x-1=='A'-1&&y-1=='C'-1)||(x-1=='C'-1&&y-1=='A'-1)){
		cout<<0;
		return 0;
	}else cout<<1;
	return 0;
}
