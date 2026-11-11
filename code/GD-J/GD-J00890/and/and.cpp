#include<bits/stdc++.h>
using namespace std;
int n,m,sum,g,gg;
int a[200005],s[200005];
long long t[35],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m,t[0]=1;
	for(int i=1;i<=n;i++) cin>>a[i],s[++g]=a[i];
	for(int i=1;i<=32;i++) t[i]=t[i-1]*2;
	for(int k=32;k>=0;k--)
	{
		sum=0;
		for(int i=1;i<=g;i++)
			if((s[i]&t[k])==t[k])
				sum++;
		if(sum<m) continue;
		ans+=t[k],gg=0;
		for(int i=1;i<=g;i++)
			if((s[i]&t[k])==t[k])
				a[++gg]=s[i];
		for(int i=1;i<=gg;i++) s[i]=a[i];
		g=gg;
	}
	cout<<ans;
	return 0;
}
