#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
long long nums;
void checks(long long x,long long num,long long cnt,long long maxx){
	if(num>m||x>n){
		nums=max(nums,cnt);
		return ;
	}
	if(a[x]!=maxx) 	checks(x+1,num,cnt,maxx);
	if(a[x]>maxx){
		num+=cnt*(a[x]-maxx);
		maxx=a[x];
		checks(x+1,num,cnt+1,maxx);
	}
	else if(a[x]==maxx){
		checks(x+1,num,cnt+1,maxx);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	bool check=0;
	for(int i=3;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1]) check=1;
	}
	if(check==0) {
		long long num=a[2]-a[1];
		long long cnt=0,ans=0;
		while(cnt<=m){
			cnt*=2;cnt+=num;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	else{
		long long ans=-1;
		for(long long i=1;i<=n;i++){
			nums=0;
			long long g=0,gg=1;
			checks(i,g,gg,a[i]);
			ans=max(ans,nums);
		}
		cout<<ans-1;
	}
	
	return 0;
}