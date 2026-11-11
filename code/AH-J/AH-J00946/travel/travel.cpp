#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt=0;
int main(){
	freopen("travel4.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	for(ll i=0;i<=2;i++){
		if(s1[i]==s2[i]) cnt++;
	}
	if(cnt==2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	for(ll i=2;i<=2;i++){
		if(s1[i]>='A'&&s1[i]<='C'&&s2[i]>='D'){
			cout<<"00";
			return 0;
		}
		else{
			cout<<"1";
		}
	}
	for(ll i=2;i<=2;i++){
		if(int(s1[i])+1==int(s2[i])||int(s1[i]-1)==int(s2[i])) cout<<"1";
		else cout<<"0";
	}
	return 0;
}
