#include <bits/stdc++.h>
using namespace std;

long long n,m,ans;
long long a[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		long long sum=0,j=i,g=0;
		while(1){
			sum+=a[i]-a[j];
			if(sum>m||j<1)break;
			g++;
			j--;
		}
		if(g==n-i){
			cout<<g;
			return 0;
		}
		ans=max(ans,g);
	}
	cout<<ans;
	return 0;
} 
