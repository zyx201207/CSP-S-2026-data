#include<bits/stdc++.h>
using namespace std;
long long n,a[200500],ans=0;
char c[200500];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x>>c[i];
		a[i]=x;
	}
	int l=1,r=n;
	for(;l<r;){
		int x=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=x;
		a[l]-=x,a[r]-=x;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
	return 0;
}

