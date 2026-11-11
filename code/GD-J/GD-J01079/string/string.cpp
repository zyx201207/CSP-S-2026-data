#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,s[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(s[l]<s[r]){
			if(c[l]!=c[r]) ans+=s[l];
			s[r]-=s[l];
			l++;
		}else if(s[l]==s[r]){
			if(c[l]!=c[r]) ans+=s[l];
			l++,r--;
		}else{
			if(c[l]!=c[r]) ans+=s[r];
			s[l]-=s[r];
			r--;
		}
	}
	cout<<ans;
	return 0;
}
