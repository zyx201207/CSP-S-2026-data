#include<bits/stdc++.h>
using namespace std;
string s;
using ll =long long;
ll n,ans,len,maxs,a[200100];
char c[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	cin>>a[1]>>c[1];
	maxs=1;
	for(int i=2;i<=n;++i){
		ll x;
		char ch;
		cin>>x>>ch;
		len+=x;
		if(ch==c[i-1]){
			a[maxs]+=x;
		}else{
			a[++maxs]=x,c[maxs]=ch;
		}
	}
	for(int i=1,j=maxs;i<=j;i++,j--){
		if(a[j]!=a[i]||c[j]!=c[i]){
			ans=-1;
			break;
		}
	}
	if(!ans){
		cout<<0;
		return 0;
	}
	ans=0;
	for(int i=1;i<=maxs;i++){
		for(int j=1;j<=a[i];j++)s.push_back(c[i]);
	}
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
}
