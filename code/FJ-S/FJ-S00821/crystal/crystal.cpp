#include <bits/stdc++.h>//int rp; while(1) rp++;
using namespace std;
long long n,m,a[500005],ans=1,maxi;
bool te1=true,te2=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) te1=false;
		if(i>2){
			if(a[i]-a[i-1] != a[i-1]-a[i-2]) te2=false;
		}	
	} 
	if(te1){
		int j=1;
		while(m-j>=0) m-=j,ans++,j++;
		cout<<ans<<'\n';
		return 0;
	}
	if(te2){
		int j=a[2]-a[1],s=a[2]-a[1];
		while(m-j>=0) m-=j,j+=s,ans++;
		cout<<ans<<'\n';
		return 0;
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		long long j=i-1,v=m,sum=1;
		while(v-(a[i]-a[j])>=0 && j>0){
			sum++; v-=(a[i]-a[j]);
			j--;
		}
		ans=max(ans,sum);
	}//I con't found a way to get AC of this problem. 
	cout<<ans<<'\n'; //NO NO NO,IT WILL TLE
	return 0;
}
