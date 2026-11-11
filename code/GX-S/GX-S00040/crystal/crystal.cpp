#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			if(j-i+1<ans){
				continue;
			}
			long long h=0;
			long long w=1;
			for(long long k=i;k<=j;k++){
				h+=a[k];
				w++;
			}
			h+=m;
			if(h/w==a[j]&&w>ans){
				ans=w;
			}
		}
	}
	cout<<ans;
	return 0;
}
