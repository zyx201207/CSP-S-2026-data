#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>ma){
				ma=a[i];
			}
		}
	}
	if(m==2){
		long long c[200005]={0},d[200005]={0},ans[200005]={0},cnt=0,cnt1=0,ma1=0,vis=1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int z=a[i],v=a[j];
				while(z>0){
					c[++cnt]=z%2;
					z/=2;
				}
				while(v>0){
					c[++cnt1]=v%2;
					v/=2;
				}
//				reverse(c+1,c+cnt+1);
//				reverse(d+1,d+cnt1+1);
				for(int h=1;h<=min(cnt,cnt1);h++){
					if(c[h]==d[h]&&c[h]==1){
						ans[h]=1;
					}
				}
				for(int h=1;h<=min(cnt,cnt1);h++){
					if(ans[h]==1){
						ma1+=vis;
					}
					vis*=2;
				}
				if(ma1>ma);
					ma=ma1;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]>ma){
				ma=a[i];
			}
		}
	}
	cout<<ma;
	return 0;
}
