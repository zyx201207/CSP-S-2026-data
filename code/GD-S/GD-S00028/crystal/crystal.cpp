#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],b[5010][5010],ans=1;
long long sum,m,f;
bool check(int k){
	for(int i=1;i<k;i++){
		sum+=(long long)abs(a[k]-a[i]);
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				b[i][j]=a[j]-a[i];
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=i-1;j++){
				sum+=b[j][i];
			}
			if(sum<=m)ans=i;
			else break;
			sum=0;
		}
		cout<<ans;
	}else{
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				f=1;
				break;
			}
		}
		if(f==0){
			ans=0;
			long long int k;
			k=abs(a[2]-a[1]);
			long long int s=m/k;
			for(int i=1;;i++){
				s-=i;
				if(s<0)break;
				ans++;
			}
			cout<<ans;
		}else{
			int l=1,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(check(mid)){
					l=mid+1;
					ans=mid;
				}else r=mid-1;
				sum=0;
			}
			cout<<ans;
		}
	}
	return 0;
}
