#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int cnt=0;
struct shorts{
	int k;
	char a;
	int l,r;
}s[200010];
int len;
int l[200010],r[200010];
int ans=0;
int L,R;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].k>>s[i].a;
		s[i].r=s[i-1].r+s[i].k;
		s[i].l=s[i].r-s[i].k+1;
		len+=s[i].k;
	}
	L=n;
	R=n;
	for(int i=1;i<=n;i++){
		if(s[i].l>len/2) break;
		while(s[L].l>len-s[i].r+1) L--;
		while(s[R].l>len-s[i].l+1) R--;
		for(int j=L;j<=R;j++){
			if(s[j].r<=len/2) break;
			if(s[i].a!=s[j].a){
				ans+=min(s[j].r,len-s[i].l+1)-max(s[j].l,len-s[i].r+1)+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
