#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500010],ans=-1,c[500010];
bool change[500010];
void slove(LL dep){
	if(dep<=0){
		for(int i=0;i<n;i++) c[i]=a[i];
		sort(c,c+n);
		LL l=0,len=-1;
		for(LL i=1;i<n;i++){
			if(c[i]==c[l]) continue;
			len=max(len,i-l);
			l=i;
		}
		len=max(len,n-l);
		ans=max(ans,len);
		return;
	}
	for(LL i=0;i<n;i++){
		if(change[i]) continue;
		change[i]=1;
		for(LL t=0;t<=dep;t++){
			a[i]+=t;
			slove(dep-t);
			a[i]-=t;
		}
		change[i]=0;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(LL i=0;i<n;i++) cin>>a[i];
	for(LL i=0;i<=m;i++) slove(i);
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
