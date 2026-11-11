#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
const int MAXN=200005;
int n;
struct node{
	int x;
	char s;
}a[MAXN];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].s;
	int m;
	int i=1,j=n;
	while(i<=j)
	{
		if(a[i].s!=a[j].s) ans+=min(a[i].x,a[j].x);
		m=max(a[i].x,a[j].x)-min(a[i].x,a[j].x);
		if(a[i].x>=a[j].x&&m!=0)
		{
			a[i].x=m;
			j--;
		}
		else if(a[i].x<a[j].x&&m!=0){
			a[j].x=m;
			i++;
		}
		else{
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
