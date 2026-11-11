#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],suml,sumr,l,r,d[500005],cnt,sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	for(int i=1;i<=n;i++){
		if(d[l]!=0){
			suml+=a[i]-a[d[l]];
		}
		sumr=sumr+(a[i]-a[d[r]])*cnt;
		while(sumr>m&&l<r){
			sum-=suml;
			suml-=(a[d[l]+1]-a[d[l]])*cnt;
			sumr-=a[i]-a[d[l]];
			cnt--;
			l++;
		}
		//cout<<sumr<<" ";
		d[++r]=i;
		cnt++;
		//cout<<cnt<<endl;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
