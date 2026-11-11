#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+9;
ll m,a[maxn],mm,ans,maxx=-1,len;
int n,cnt;
bool f=0;
struct node
{
	int c;
	ll z;
}b[maxn];
int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	b[++cnt].z=a[1];
	b[cnt].c=1;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1])
		b[++cnt].c++,b[cnt].z=a[i];
		else
		b[cnt].c++,b[cnt].z=a[i];
	}
	mm=m;
	for(int i=cnt;i>=1;i--)
	{
		ans+=b[i].c;
		len=b[i].z;
		for(int j=i-1;j>=1;j--)
		{	ll num=b[j].c*(len-b[j].z);
			if(mm>=num)
			mm-=num,ans+=b[j].c;
			else
			ans+=(mm/(len-b[j].z)),f=1;
			if(f==1) break;
		}
		maxx=max(ans,maxx);
		ans=0;f=0;mm=m;
	}
	cout<<maxx<<'\n';
	return 0;
}

