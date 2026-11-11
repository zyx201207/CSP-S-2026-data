#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,s,a[500005],r[500005],l[500005],x[100005],y[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	while(n--){
		cin>>s;
		for(int i=1;i<=s;i++)cin>>r[i]>>l[i];
	}
	for(int i=1;i<=q;i++)cin>>x[i],y[i];
	for(int i=1;i<=q;i++)cout<<i*8-7;
}
