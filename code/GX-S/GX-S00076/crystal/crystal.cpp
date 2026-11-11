#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> vec(n),sum(n);
	for(int i=0;i<n;i++) cin>>vec[i];
	sort(vec.begin(),vec.end());
	sum[0]=vec[0];
	for(int i=1;i<n;i++) sum[i]=sum[i-1]+vec[i];
	long long ans=0;
	int j=0;
	for(int i=0;i<n;i++){
		long long nums=i+1-j,s;
		if(j==0) s=sum[i];
		else s=sum[i]-sum[j-1];
		if(s+m>=nums*vec[i]){
			ans=max(ans,nums);
		}else{
			j++,i--;
		}
	}
	cout<<ans;
}
