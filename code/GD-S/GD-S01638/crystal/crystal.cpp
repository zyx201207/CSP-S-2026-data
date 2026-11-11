#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+7;
int n,a[N],b[N],m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int asd=0,ans=0,k=0;
	for(int i=1,j=1;i<=n;i++){
		for(;j<=n;j++){
			if(i>j)continue;
			//cout<<i<<" "<<j<<" "<<b[j]-b[i-1]<<"\n";
			int k=a[j]*(j-i+1)-b[j]+b[i-1];
			if(k>m)break;
			ans=max(j-i+1,ans);
		}
	}
	cout<<ans;
	
}
