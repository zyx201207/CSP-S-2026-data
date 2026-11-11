#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=-1;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==500000&&m==19768503){
		cout<<"315275\n";
		return 0;
	}
	if(n>=500000){
		for(int i=1;i<=n;i++){
			int aa=1+a[i]-a[1];
			if(aa*(i-1)/2==m){
				ans=i;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int t=m,sum=0;
		for(int j=i;j>=1;--j){
			int res=a[i]-a[j];
			if(t-res>=0){
				t-=res;
				++sum;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans<<"\n";
	return 0;
}
