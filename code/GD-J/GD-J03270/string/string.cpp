#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,b[200005],ans;
char a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>b[i]>>a[i];
	int l=1,r=n;
	while(l<r)
	{
		if(a[l]!=a[r])
		{
			if(b[l]<b[r]) ans+=b[l],b[r]-=b[l],l++;
			else ans+=b[r],b[l]-=b[r],r--;
		}
		else
		{
			if(b[l]<b[r]) b[r]-=b[l],l++;
			else b[l]-=b[r],r--;
		}
	}
	cout<<ans;
	return 0;
}
