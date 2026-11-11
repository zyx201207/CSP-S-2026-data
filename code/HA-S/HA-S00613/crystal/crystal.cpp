#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500005],mid,ans=LLONG_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bool same=1;
	LL c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=c)same=0; 
	}
	if(same){
		LL t=m;
		ans=1;
		int i=1;
		while(t>=(c*i)&&ans<n){
			if(t>=2*c*i){
				if(ans+2>n){
					ans++;
					break;
				}
				ans+=2;
				t-=2*c*i;
			}
			else{
				t-=c*i;
				ans++;
			}
			i++;
		}
		cout<<ans<<"\n";
		return 0;
	}
	int l=1,r=1;
	while(l<=r&&r<=n){
		bool f=1;
		LL t=m;	
		for(int i=l;i<=r;i++){
			if(a[r]-a[i]<=t){
				t-=a[r]-a[i];
			}
			else{
				f=0;
				break;
			}
		}
		if(f){
			ans=ans>(r-l+1)?ans:(r-l+1);
			r++;
		}
		else l++;
	}
	cout<<(ans==LLONG_MIN?1:ans)<<"\n";
	return 0;
} 
