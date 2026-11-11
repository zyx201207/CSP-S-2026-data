#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int k,n,m,sum;
int a[N],b[N];
char c[N],z[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>k;
	char x;
	for(int i=1;i<=k;i++)
	{
		int t;
		cin>>t>>x;
		if(x==c[n]) a[n]+=t;
		else a[++n]=t,c[n]=x;
		sum+=t;
	}
	int len=0,mid;
	bool y=1;
	for(int i=1;i<=n;i++)
	{
		if(len+a[i]<=sum/2||!y)
			b[++m]=a[i],z[m]=c[i],len+=a[i];
		else
			if(sum%2==0)
			b[++m]=sum/2-len,z[m]=c[i],mid=m,
			b[++m]=a[i]-(sum/2-len),z[m]=c[i],y=0;
			else 
			b[++m]=sum/2-len,z[m]=c[i],mid=m,
			b[++m]=a[i]-(sum/2-len+1),z[m]=c[i],y=0;
	}
	int ans=0;
	for(int i=1,j=m,ni=0,nj=0;i<=mid;)
	{
		int x=b[i]-ni,y=b[j]-nj;
		if(z[i]==z[j])
			if(x>y) ni+=y,j--,nj=0;
			else nj+=x,i++,ni=0;
		else 
			if(x>y) ans+=y,ni+=y,j--,nj=0;
			else ans+=x,nj+=x,i++,ni=0;
	}
	cout<<ans;
	return 0;
}

