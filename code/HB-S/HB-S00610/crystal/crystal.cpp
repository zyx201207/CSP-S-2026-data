#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,now=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int h=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((i>1)&&(a[i]<a[i-1]))h=1;
	}
	if(h)sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		m-=now*(a[i]-a[i-1]);
		now++;
		while(m<0){
			now--;
			m+=(a[i]-a[i-now]);
		}
		ans=max(now,ans);
	}
	cout<<ans;
	return 0;
}
