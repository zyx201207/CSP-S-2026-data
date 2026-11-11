#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	ll ok=0;
	if(c1==c2)cout<<1,ok=1;
	else cout<<0;
	ll ans=s1[0]*10+s1[1];
	ll ans2=s2[0]*10+s2[1];
	if(ans==ans2&&ok==1){
		cout<<1;
		ok=2;
	}
	else cout<<0;
	if(abs(s1[2]-s2[2])<=2&&ok==2&&s1[2]!=s2[2])cout<<1;
	else cout<<0;
	if(abs(s1[2]-s2[2])==1&&ok==2)cout<<1;
	else cout<<0;
	return 0;
}
