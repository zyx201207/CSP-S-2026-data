#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,M=1e9+10;
int n,a[N],cnt,s[M],q,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		char c;
		cin>>c;
		for(int j=1;j<=a[i];j++) s[++q]=(int)(c-'a'+1);
	}int w=0;
	for(int i=1;i<=q-1;i++){
		if(s[i]!=s[i+1]) {
			w=1;
			break;
		}
	}if(!w){
		cout<<0;
		return 0;
	}
	if(q%2==0){
		cnt=1;
		for(int i=q/2;i>=1;i--){
			if(s[i]!=s[i+cnt]) ans++;
			cnt+=2;
		}
	}else{
		cnt=0;
		for(int i=q/2+1;i>=1;i--){
			if(s[i]!=s[i+cnt]) ans++;
			cnt+=2;
		}
	}printf("%lld",ans);
	return 0;
}
