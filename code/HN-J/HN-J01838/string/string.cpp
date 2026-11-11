#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
string s;
ll a[N],n,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	string t=s;
	reverse(t.begin(),t.end());
	if(t==s){
		cout<<0;
		return 0;
	}
	if(s.size()%2==0){
		for(ll i=0,j=s.size()-1;i<s.size()/2;i++,j--){
			if(s[i]!=s[j]){
				ans++;
			}
		}
	}else{
		for(ll i=0,j=s.size()-1;i<s.size()/2+1;i++,j--){
			if(s[i]!=s[j]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

