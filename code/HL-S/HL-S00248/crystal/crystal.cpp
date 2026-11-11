#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+1+n);
	int l=1,r=1,tmp=0;
	for(int i=1;i<=n;i++){
		if(tmp+(r-l+1)*(a[r+1]-a[r])<=m){
			tmp=tmp+(r-l+1)*(a[r+1]-a[r]);
//			cout<<tmp<<endl;
			r++;
			if(r>n){
				break;
			}
//			cout<<">>>>> = "<<l<<' '<<r<<endl;
			ans=max(ans,r-l+1);
		}
		else{
			while(tmp+(r-l+1)*(a[r+1]-a[r])>m){
				tmp=tmp-a[r]+a[l];
//				cout<<tmp<<endl;
				l++;
//				r++;
				if(l>n){
					break;
				}
//				cout<<">>>>> = "<<l<<' '<<r<<endl;
			}
			tmp=tmp+(r-l+1)*(a[r+1]-a[r]);
			r++;
			ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	return 0;
}

