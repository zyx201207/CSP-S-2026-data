#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n,a[N],ld=1,rd;
long long l,r,ans,ed[N],fed[N],tp;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n,rd=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],r+=a[i],ed[i]=r;
	r=0;
	for(int i=n;i;i--)tp+=a[i],fed[i]=tp;
	for(;ld<rd;)
		if(ed[ld]<fed[rd])ans+=(c[ld]!=c[rd])*(ed[ld]-l),r=l=ed[ld],ld++;
		else if(ed[ld]>fed[rd])ans+=(c[ld]!=c[rd])*(fed[rd]-r),l=r=fed[rd],rd--;
		else ans+=(c[ld]!=c[rd])*(ed[ld]-l),l=ed[ld],r=fed[rd],ld++,rd--;
	cout<<ans;
	return 0;
}
