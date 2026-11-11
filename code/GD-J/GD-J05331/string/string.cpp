#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int a[200005];
char c[200005];
signed main(){
	fast;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,len=0;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],len+=a[i];
	int i=1,j=n,sum1=0,sum2=len;
	while(sum1<sum2){
		int minn=min(a[i],a[j]);
		if(c[i]!=c[j]){
			ans+=minn,sum2-=minn,sum1+=minn,a[i]-=minn,a[j]-=minn;
			if(!a[j])j--;
			if(!a[i])i++;
		}else{
			sum2-=minn,sum1+=minn,a[i]-=minn,a[j]-=minn;
			if(!a[j])j--;
			if(!a[i])i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
