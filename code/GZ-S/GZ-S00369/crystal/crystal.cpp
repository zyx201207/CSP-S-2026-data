//GZ-S00369 六盘水市第二十四中学 王胤杰 
#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long n,m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		long long cnt=1,x=m;
		for(long long j=i-1;j>=1;j--){
			if(x>=a[i]-a[j]){
				x-=(a[i]-a[j]);
				a[j]=a[i];
				cnt++;
			}else{break;}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
