#include<bits/stdc++.h>
#define llq long long
using namespace std;
llq n,m,a[500005],c[500005],top=0,ans=0,flag=0,cnt[500005],cf[500005],cge=0,d[500005],znt=0,l=1,r=0;
bool cmp(llq x,llq y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-1;i++){
		cf[i]=a[i]-a[i+1];
		cnt[i]=cnt[i-1]+cf[i];
	}
	while(znt<n-1){
		znt++;
		d[++r]=cnt[znt];
		cge+=d[r];
		while(cge-(r-l+1)*flag>m){
			cge-=d[l];
			l++;
			flag+=cf[l-1];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans+1;
	if(ans==0) cout<<ans;
	return 0;
}
//CCFwcnm
