#include<bits/stdc++.h>
using namespace std;
int n,l,r,min1,ans=1;
long long m,a[500005],b[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int o=1;o<=n;o++){//cout<<'\n'<<o<<'\n';
		cin>>a[o];
	}sort(a+1,a+1+n);
	for(int o=1;o<=n;o++){//cout<<'\n'<<o<<'\n';
		cin>>a[o];
		b[o]=b[o-1]+(o-1)*(a[o]-a[o-1]);
		l=1;r=o;
		for(;l<r;){
			min1=(l+r)/2;
			//cout<<l<<' '<<r<<' '<<min1<<'\n';
			if(b[o]-b[min1-1]-(long long)(min1-1)*(a[o]-a[min1-1])<=m){
				ans=max(ans,o-min1+1);
				r=min1;
			}else{
				l=min1+1;
			}
		}//cout<<l<<' '<<r<<'\n';
	}cout<<ans;
	return 0;
} 
