#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int t,h,n,a[N];
char c[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	h=n;
	t=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(t<h){
		int tt=t,hh=h;
		int qz=0;//差值 
		int wx=0;//公共值 
		if(a[t]>a[h])qz=a[t]-a[h],wx=a[h],a[t]-=a[h],h--;
		else qz=a[h]-a[t],wx=a[t],a[h]-=a[t],t++;
		if(c[tt]!=c[hh])ans+=wx;
	}
	cout<<ans;
	return 0;
}

