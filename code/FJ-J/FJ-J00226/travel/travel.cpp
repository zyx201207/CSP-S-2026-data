#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue
#define st stack
#define qu queue
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int main(){
	qwq;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[5],s1[5],c2[5],s2[5];
	cin>>c1>>s1>>c2>>s2;
	ll flag=1;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
	}else{
		flag=0;
		cout<<0;
	}
	if(flag&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		flag=0;
		cout<<0;
	}
	if(flag&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
		cout<<1;
	}else{
		flag=0;
		cout<<0;
	}
	if(flag&&((ll)(s1[2])-(ll)(s2[2])==1||(ll)(s2[2])-(ll)(s1[2])==1)){
		cout<<1;
	}else{
		flag=0;
		cout<<0;
	}
	return 0;
}
