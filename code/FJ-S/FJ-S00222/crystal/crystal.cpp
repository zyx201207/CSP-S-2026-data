#include<bits/stdc++.h>
#define int long long
using namespace std;
struct compp{
	int val,xu;
}com[500005];
int n,m,a[500005],qianqian[500005],qian[500005],ans[500005],ank,ji,cnt;
bool cmp(compp i,compp j){
	if(i.val!=j.val) return i.val<j.val;
	else return i.xu>j.xu;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) ji++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) cnt=i;
		qianqian[i]=a[i]*(cnt-1)-ans[i-1];
		if(a[i]!=a[i-1]) ans[i]=ans[i-1]+a[i];
		else ans[i]=ans[i-1];
		com[i]={qianqian[i],i};
	}
	sort(com+1,com+n+1,cmp);
	if(ji==0){
		for(int i=1;i<=n;i++){
			if(qianqian[i]>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	int xuu=com[1].xu,vall=com[1].val;
	for(int i=1;i<=n;i++){
		if((i!=1&&com[i].val<=vall)||com[i].xu<=ank) continue;
		vall=com[i].val;
		xuu=com[i].xu;
		int anss=0,ccan=0;
		anss+=a[i]*ank+ans[i-ank]-ans[i];
		if(anss>m) continue;
		for(int j=i-ank;j>=1;j--){
			anss+=a[i]-a[j];
			if(anss>m){
				ank=max(ank,i-j);
				ccan=1;
				break;
			}
		}
		if(ccan==0) ank=max(ank,xuu);
	}
	cout<<ank;
	return 0;
}
