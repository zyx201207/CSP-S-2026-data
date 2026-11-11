#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int n;
LL sum,a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	LL sl=a[l],sr=a[r];
	while(l<r){
		LL minn=min(sl,sr);
		if(c[l]!=c[r]) sum+=minn;
		sl-=minn,sr-=minn;
		if(!sl) sl=a[++l];
		if(!sr) sr=a[--r];
	}
	cout<<sum;
	return 0;
}//Accepted
