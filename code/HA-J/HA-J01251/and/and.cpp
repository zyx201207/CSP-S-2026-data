#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005],b[200005],ans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>a[i];
	if(m==1){
	for(int i=0;i<n;++i)ans=max(ans,a[i]);
}
	else{
		sort(a,a+n);
		for(int i=n-1;i>=n-m+1;++i){
			if(i==n-1)ans=a[i];
			else{
				int j;
				for(j=i-1;j>m;--j){
					ans=max(ans&=a[i],ans&=a[i-j]);
				}
			}
		}
	}
	
	cout<<ans;
}
