#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[555555];
long long check(long long mid){
	long long sum_jl=0,i=1;
	for(;i<=n&&a[i]<=mid;i++){
		sum_jl+=(mid-a[i]);
	}
	if(sum_jl<=m)return i-1;
	else return -1e13;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool is_dcsl=true;//yl:16~18
	bool is_alli=true;//yl:13~15 
	bool is_alsa=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			if(a[i]-a[i-1]!=a[2]-a[1]){
				is_dcsl=false;
			}
		}
		if(a[i]!=a[1])is_alsa=false;	
		if(a[i]!=i)is_alli=false;
	}
	if(is_alsa){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	if(is_alli||is_dcsl){//30'
		long long s[n+3]={0};
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+abs(a[i]);
		}
		if(s[1]>m){
			cout<<1;
			return 0;
		}
		for(int i=n;i>=1;i--){
			if(s[i]<=m){
				cout<<i+1;
				break; 
			}
		}
		return 0;
	}
	long long mi=1e12+1,ma=-1e12-1,ans=-1e12-1;
	for(int i=1;i<=n;i++){
		mi=min(mi,a[i]);
		ma=max(ma,a[i]);
	} 
	long long l=mi,r=ma;
	for(int i=ma;i>=mi;i--){
		long long cur=check(i);
		if(cur>ans){
			ans=cur;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}                       
