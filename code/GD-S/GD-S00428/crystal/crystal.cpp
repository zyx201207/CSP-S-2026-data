#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int cha=0;
	bool foola=1,foolb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=i)foola=0;
		if(i==2)cha=a[i]-a[i-1];
		if(i>=3&&a[i]-a[i-1]!=cha){
			foolb=0;
		}
	}
	if(foola==1||foolb==1){
		int cnt=0;
		while(m>0){
			cnt++;
			m-=cha*cnt;
			if(m>=0)ans++;
		}
		cout<<ans;
		return 0;
	}
	int sum,x;
	for(int i=n;i>=1;i--){
		int j=i;
		sum=0;
		x=m;
		while(x>=a[i]-a[j]&&j>=1){
			sum++;
			x-=a[i]-a[j];
			j--;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}//Oct31==Dec25?
