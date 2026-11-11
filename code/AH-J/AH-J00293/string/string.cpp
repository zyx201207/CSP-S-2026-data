#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n,a;
ll ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		cin>>c;
		while(a--) s+=c;
	}ll x=0,y=s.size()-1;
	for(;x<y;x++,y--){
		if(s[x]!=s[y]) ans++;
	}printf("%lld\n",ans);
	return 0;
}
