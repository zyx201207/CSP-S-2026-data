#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int l=2e5+5;
ll n,ans;
struct str{
	ll  a;
	char c;
}s[l];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	for(int i=1,j=n;i<=j;){
		
		ll cnt=min(s[i].a,s[j].a);
		s[i].a-=cnt;
		s[j].a-=cnt;
		if(s[i].c!=s[j].c){
			ans+=cnt;
		}
		if(s[i].a==0) i++;
		if(s[j].a==0) j--;
	}
	cout<<ans;
	return 0;
} 
