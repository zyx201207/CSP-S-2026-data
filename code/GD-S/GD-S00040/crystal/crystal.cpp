#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],ans=INT_MIN;
bool flag=0;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-1;i++){
		f[i]=f[i-1]+a[i+1]-a[i];
		if(i>=2){
			if(f[i-1]-f[i-2]!=f[i]-f[i-1]){
				flag=1;
			}
		}
	}
	if(flag==0){
		long long cnt=0;
		for(int i=1;i<=n-1;i++){
			cnt+=f[i];
			if(m<cnt){
				cout<<i;
				return 0;
			}
		}
	}else{
		for(int i=1;i<=n-1;i++){
			long long cnt=0;
			bool fl=0;
			for(int j=i-1;j>=0;j--){
				cnt+=f[i]-f[j];
				if(m<cnt){
					fl=1;
					if(ans<i-j)ans=i-j;
					break;
				}
			}
			if(fl==0&&ans<i+1){
				ans=i+1;
			}
		}
		cout<<ans;
	}
	return 0;
}
