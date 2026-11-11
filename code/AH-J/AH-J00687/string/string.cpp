#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
char x;
ll t,n,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
		scanf("%lld%lld",&t,&x);
		for(int i=1;i<=t;i++)s=s+x;
	}
	ll sum=s.size();
	for(int i=0;i<sum;i++){
		if(s[i]!=s[s.size()-i-1]){
			s[i]=s[s.size()-i-1];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
