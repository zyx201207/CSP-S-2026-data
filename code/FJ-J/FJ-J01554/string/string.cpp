#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,b[N],len;
char c[N];
stack<int > st;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>b[i]>>c[i];
	int l=1,r=n,ans=0;
	while(l<r){
		if(c[l]!=c[r]) ans+=min(b[l],b[r]);
		if(b[l]>b[r]){
			b[l]-=b[r];
			b[r--]=0;
		}
		else if(b[l]<b[r]){
			b[r]-=b[l];
			b[l++]=0;
		}
		else{
			b[l++]=0;
			b[r--]=0;
		}
	}
	cout<<ans;
	return 0;
}
