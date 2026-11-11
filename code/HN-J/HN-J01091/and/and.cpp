#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000000];
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	if(n==m){
		ans=a[1]&a[2];
		for(int i=3;i<=n;i++){
			ans&=a[i];
		}
	}
	int maxn=-1;
	for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
	if(m==1){
		ans=maxn;
	}
	if(maxn<=4){
		int cnt3=0,cnt2=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3)cnt3++;
			if(a[i]==2)cnt2++;
			if(a[i]==1)cnt1++;
		}
		if(cnt3==m) ans=3;
		else if(cnt3+cnt2==m)ans=2;
		else if(cnt3+cnt2+cnt1==m)ans=1;
		else ans=0;
	}
	sort(a+1,a+1+n);
	ans=a[n-m+1];
	cout<<ans;
	return 0;
}

