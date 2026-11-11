#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,sum=0,cnt=0;
string c,s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
		cin>>a>>c;
		for(ll i=1;i<=a;i++){
			s+=c;
			if(s[i]==s[i+1]) cnt++;
		}
	}
	if(cnt==(int)s.size()){
		cout<<0;
		return 0;
	}
	for(ll i=0;i<(int)s.size()/2;i++){
		if(s[i]==s[s.size()-i]) continue;
		sum++;
	}
	cout<<sum;
    return 0;
}
