#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0,cnt=1,ans=1;
	for(int l=1,r=1;l<=n,r<=n;){
		ans=max(ans,cnt);
		if(sum+cnt*(a[r+1]-a[r])<=m){
			r++;
			sum+=cnt*(a[r]-a[r-1]);
			cnt++;
		}else{
			l++;
			cnt--;
			sum+=a[l-1]-a[r];
		}
	}
	cout<<ans;
	return 0;
} 
