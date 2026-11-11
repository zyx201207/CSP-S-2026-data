#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum,ph;
	for(int i=2;i<=n;i++){
		sum=1,ph=m;
		for(int j=i-1;j>=1;j--){
			if(ph>=(a[i]-a[j])){
				ph-=a[i]-a[j];
				sum++;
			}else break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}	
