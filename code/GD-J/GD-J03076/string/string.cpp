#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll ans=0;
int main(){
	std::ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		int a; char c; cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	ll len=s.size(),chk=len/2;
	if(len&1){
		for(int i=0;i<chk+1;i++){
			if(s[i]!=s[len-1-i]){
				ans++;
			}
		}
	}else{
		for(int i=0;i<chk;i++){
			if(s[i]!=s[len-1-i]){
				ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
