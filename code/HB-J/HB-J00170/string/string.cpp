#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,cnt[30],mx,m,all,now;
struct node{
	int x;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		all+=a[i].x;
		cnt[(long long)(a[i].c)-(long long)('a')+1]+=a[i].x;
		a[i].x=all;
	}
	for(int i=1;i<=26;i++)if(mx<cnt[i])mx=cnt[i],m=i;
	for(int i=1;i<=26;i++)if(i!=m)ans+=cnt[i];
	if(all%2==1)cout<<ans-1;
	else cout<<ans;
	return 0;
}
