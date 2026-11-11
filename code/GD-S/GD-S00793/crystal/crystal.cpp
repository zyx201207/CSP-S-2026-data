#include<bits/stdc++.h>
using namespace std;
long long a[350005],n,m;
bool check(){
	for(int i=1;i<=n;i++)if(a[i]!=i)return false;
	return true;
}
bool check1(){
	int tmp=a[2]-a[1];
	for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=tmp)return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(check()||check1()){
		long long sum=0,cnt=0,tot=abs(a[2]-a[1]);
		while(sum<=m){
			cnt+=tot;
			sum+=cnt;
		}
		cout<<cnt;
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long sum=0,res=0,tot=i;
			while(sum<=m&&tot<=n){
				sum+=(a[tot]-a[i])*(tot-i);
				res++;
				tot++;
			}
			ans=max(ans,res);
		}
		cout<<ans;
	}else{
		long long sum=0,id=0;
		for(int i=1;i<=n;i++){
			if(i==1){
				while(sum+a[id+1]<=m){
					id++;
					sum+=a[id];
				}
			}else{
				sum-=a[i-1];
				while(id<=n&&sum+a[id+1]<=m){
					id++;
					sum+=a[id];
				}
			}
			ans=max(ans,id-i+1);
		}
		cout<<ans;
	}	
	return 0;
}
