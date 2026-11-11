#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    ll cnt=0,ans=0;
    string s="";
    cin>>n;
    vector<ll> a(N);
    vector<char> c(N);
    for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	if(cnt%2==0){
		cnt/=2;
		for(ll i=0;i<cnt;i++){
			if(s[i]!=s[cnt*2-i-1]) ans++;
		}
		cout<<ans<<"\n";
	}else{
		cnt/=2;
		for(ll i=0;i<cnt;i++){
			if(s[i]!=s[cnt*2-i]) ans++;
		}
		cout<<ans<<"\n";
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

