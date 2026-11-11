#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans;
long long step;
long long total;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	ans=0;
	for(long long i=1;i<=n;i++){
		step=0;
		total=0;
		for(long long j=i-1;j>=1;j--){
			if(step+a[i]-a[j]>m) break;
			else{
				step+=a[i]-a[j];
				total++;
			}
		}
		ans=max(total,ans);
	}
	cout<<ans+1;
	return 0;
} 
