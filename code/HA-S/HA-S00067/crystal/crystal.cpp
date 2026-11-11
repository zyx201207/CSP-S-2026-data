#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long g=0;
	long long ans=0;
	long long sum=0,ff=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=0;
		g=m;
		sum=0;
		for(int j=1;j<=n;j++){
			sum=min(sum,a[i]-a[j+1]);
		}
		for(int j=1;j<=n;j++){
			if(sum==a[i]-a[j+1]&&g-sum>=0){
				a[j+1]+=sum;
				g-=sum;
				sum=min(sum,a[i]-a[j+1]);
				if(a[i]==a[j]){
					ans++;
				}
			}
			if(g==0||g-sum<0){
				break;
			}
		}
		ff=max(ff,ans);
	}
	cout<<ff;
	return 0;
}
