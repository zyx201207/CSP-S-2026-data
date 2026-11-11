#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int a[200005],n,m;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	fast;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int len=0,ans=0;
	for(int i=1;i<=n;i++){
		if(len==m)break;
		int k=a[i],sum=0;
		while(k){
			if(k%2)sum++;
			k/=2;
		}
		if(sum>1||(m-len==n-i+1)){
			if(!len)ans=a[i];
			else ans&=a[i];
			len++;
		}
	}
	cout<<ans;
	return 0;
}
