//GZ-S00169 ¿ÓÍª»º 
#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m1,m,s=-1e18,s1=1e18,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];s=max(a[i],s);s1=min(a[i],s1);
	}
	long long r=s,l=s1;
	while(l<=r){
		m=m1;long long cnt=0;
		long long mid=(r+1)/2+l/2;
		//cout<<l<<" "<<r<<" "<<mid<<"\n";
		for(int i=1;i<=n;i++){
			if(a[i]<=mid){
				m-=(mid-a[i]);
				if(m<0){
					r=mid-1;cout<<1<<" ";
					break;
				}
				cnt++;
			}
		}if(m>=0){
			ans=max(ans,cnt);
			l=mid+1;cout<<2<<" ";
			//if(m==0) break;
		}
		cout<<ans<<"\n";
	}
	cout<<ans;
	return 0; 
}
