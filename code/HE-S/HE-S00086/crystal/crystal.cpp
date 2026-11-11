#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N],minn=0x3f;
int ans=-0x3f;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;++i){
		cin>>a[i];
		if(a[i]-a[i-1]<minn) minn=a[i]-a[i-1];
	} 
	sort(a+1,a+n+1);
	b[n]=0;
	for(int i=n-1;i>=1;i--) b[i]=a[i+1]-a[i]+b[i+1];
	for(int i=n;i>=2;i--){
		int w=m,sum=0;
			for(int j=i-1;j>=1;j--){
				if(w>=b[j]-b[i]){
					w-=b[j]-b[i];
					sum++;
			  	}
			  	else break;
			}
		ans=max(ans,sum+1);
	}
	cout<<ans;
	return 0;
}

