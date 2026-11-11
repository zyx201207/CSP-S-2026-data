#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],posx,posy,ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	posx=1;
	posy=n;
	while(posx<posy){
		long long tmp=min(a[posx],a[posy]);
		if(c[posx]!=c[posy]) ans+=tmp;
		a[posx]-=tmp;
		a[posy]-=tmp;
		if(a[posx]==0) posx++;
		if(a[posy]==0) posy--;
	}
	cout<<ans;
	return 0;
}
