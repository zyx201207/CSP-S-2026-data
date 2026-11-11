#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxx=LLONG_MIN,minn=LLONG_MAX;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=2;i<=n;i++){
			long long cnt=1,t=m;
			for(int j=i-1;j>=1;j--){
				int f=a[i]-a[j];
				if(t-f>=0){
					t-=f;
					cnt++;
				}
				else{
					break;
				}
			}
			maxx=max(cnt,maxx);	
		}
		cout<<maxx;
	}
	else if(n>=5000){
		long long ans=0;
		for(int i=2;i<=n;i++){
			if(abs((a[1]+a[i])*i/2-m)<minn){
				minn=abs((a[1]+a[i])*i/2-m);
				ans=i;
			}
		}
		cout<<ans;
	}
	return 0;
}
