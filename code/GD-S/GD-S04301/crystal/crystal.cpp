#include<bits/stdc++.h>
using namespace std;
int n;
long long m,t,l,r,he,ans=1;//he ºÍ 
long long a[500005];
long long c[500005];//²î·Ö 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) c[i]=a[i]-a[i-1];
	l=2;r=2;
	while(r<=n){
		t+=c[r]*(r-l+1);
		r++;
		he+=c[r];
		while(t>m&&l<=r){
			t-=he;
			he-=c[l];
			l++;
		}
		if(r-l+1>ans) ans=r-l+1;
	}
	cout<<ans;
	return 0;
	//15:30 finish
}
