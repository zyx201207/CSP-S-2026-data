#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,p,l=1,r;
struct node{
	int a;
	char c;
}b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for (int i=1;i<=n;++i) cin>>b[i].a>>b[i].c;
	while (l<r){
		if (b[r].a>b[l].a){
			b[r].a-=b[l].a;
			if (b[r].c!=b[l].c) ans+=b[l].a;
			++l;
		}
		else {
			b[l].a-=b[r].a;
			if (b[r].c!=b[l].c) ans+=b[r].a;
			--r;
		}
	}
	cout<<ans;
	return 0;
}
