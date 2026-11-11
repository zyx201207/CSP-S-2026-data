#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+5;
long long a[maxn],b[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long cnt=0;
		for(int j=i;j>=1;j--){
			if(b[i]+a[i]-a[j]>m)break;
			else b[i]+=a[i]-a[j],cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
