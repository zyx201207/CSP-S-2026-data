#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string as=s1.substr(0,2);
	string bs=s2.substr(0,2);
	if(as==bs) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]<=67&&s2[2]<=67||s1[2]>67&&s2[2]>67) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1)  cout<<1;
	else cout<<0;
	
	return 0;
}
