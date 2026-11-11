#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int t=0,poi=0;
		sum[1]=a[i]-a[1];
		for(int j=2;j<=n;j++){
			sum[j]=a[i]-a[j];
		}
		sort(sum+1,sum+n+1);
		int l=m,flag=0,q=1;
		while(flag==0 and q<=n){
			if(sum[q]>l){
				flag=1;
				break;
			}
			if(sum[q]<0){
				q++;
				continue;
			}
			if(sum[q]>=0){
				l-=sum[q];
				q++;
				t++;
			}
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}
