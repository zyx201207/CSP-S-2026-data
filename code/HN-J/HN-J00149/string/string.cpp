#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+7;
struct node{
	int sum;
	char c;
}s[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].sum>>s[i].c;
	int l=1,r=n;
	while(l<r){
		int tmp=min(s[l].sum,s[r].sum);
		s[l].sum-=tmp;
		s[r].sum-=tmp;
		if(s[l].c!=s[r].c) ans+=tmp;
		if(s[l].sum==0) l++;
		if(s[r].sum==0) r--;
	}
	cout<<ans;
	return 0;
}
