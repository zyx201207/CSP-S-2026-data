#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500010];
long long pre1[500010];
long long pre2[500010];
long long tot;
long long l,r;
long long cnt;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		pre1[i]=pre1[i-1]+a[i]-a[i-1];
		pre2[i]=a[i]-a[i-1];
	}
    l=n,r=n;
	while(l>0){
		tot+=pre1[r]-pre1[l];
		if(tot<=m) l--;
		else{
			cnt=max(cnt,r-l);
			while(tot>m){
				tot-=(r-l)*pre2[r];
				r--;
			}
			l--;
		}
	}
	cnt=max(cnt,r);
	cout<<cnt;
	return 0;
}
