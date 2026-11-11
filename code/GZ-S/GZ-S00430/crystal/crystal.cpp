//GZ-S00430,贵阳市第一中学，陶昱泽
#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long a[N];
int n,m;
long long an,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1,j=1;i<=j&&j<=n;i++){
		while(an<=m&&j<=n){
			ans=max(j-i+1,ans);
			j++;
			if(j<=n){
			long long c=(a[j]-a[j-1])*(j-i);
			an+=c;
			}
		}
		if(j<=n){
		an+=a[i];
		an-=a[j];
	}
	}
	cout<<ans;
	return 0;
}  
