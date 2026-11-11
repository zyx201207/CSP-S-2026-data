#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,zm,ans,zans,d[500005],s,t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+((i-1)*(a[i]-a[i-1]));
		s+=t*(a[i]-a[i-1]);
		if(d[i]-s<=m)ans=max(ans,i-t);
		else{
			while(d[i]-s>m){
				t++;
				s+=(a[i]-a[t]);
			}ans=max(ans,i-t);
		}
	}cout<<ans;
	return 0;
} 
