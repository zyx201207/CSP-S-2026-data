#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
int n,ans=0;
ll m;
ll a[N];
int firstmore(int x){
	int l=1;
	int r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]<=a[x])l=mid+1;
		else r=mid;
	}
	return r;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(a,0,sizeof(a));
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ss=firstmore(1);
    for(int i=ss;i<=n;i++){
    	if(a[i]==a[i-1])continue;
    	int start=i-1;
        int tt=m;
        int cur=firstmore(i)-i;
        while(tt>0&&start>0){
        	tt-=(a[i]-a[start]);
        	start--;
        	if(tt<0)break;
        	cur++;
		}
		ans=max(ans,cur);
	}
	cout<<ans;
	return 0;
}
