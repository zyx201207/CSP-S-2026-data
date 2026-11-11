#include<bits/stdc++.h>
using namespace std;
long long sum,m,cnt,maxn;
long long a[200005];
long long l=1,f[1000005];
long long r=1;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	while(1){
		int cnt=0;
		while(r<n&&m-(a[r+1]*(r+1-l)-(f[r]-f[l-1]))>=0){
			r++;
			cnt++;
			//cout<<l<<" "<<r<<endl;
			maxn=max(maxn,r-l+1);
		}
		while(l<n&&m-(a[r+1]*(r+1-l)-(f[r]-f[l-1]))<0){
			l++;
			cnt++;
		}
		if(cnt==0)break;
	}
	cout<<maxn;
	return 0;
}
