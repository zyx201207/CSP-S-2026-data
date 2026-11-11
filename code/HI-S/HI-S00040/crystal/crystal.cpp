#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
long long n,m,a[500005],maxn,v[500005]={1,1};
pair<long long,long long> x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		auto xf=x.first+x.second*(a[i]-a[i-1]);
		if(i>1)v[i-1]=v[i-2]*(a[i]-a[i-1]);
		if(xf>m){
			xf-=v[i-1]*a[i-x.second];
			v[i-1]/=v[i-x.second];
			if(xf>m){
				cout<<x.second; 
				break;
			}
		}
		x.first=xf;
		x.second++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

