#include<bits/stdc++.h>
using namespace std;
int n,tans;
long long m,a[500005],orgdiv[500005],totdiv[500005],sumdiv[500005];
//deque<int>fmaxs,bmaxs;
inline bool check(int st,int ed){
	return (sumdiv[st]-sumdiv[ed])-(totdiv[ed-1]-totdiv[st-1])*(n-ed)<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	/*
	for(int i=1;i<=n;i++){
		while(!fmaxs.empty()&&a[fmaxs.back()]<a[i]){
			fmaxs.pop_back();
		}
		if(!fmaxs.empty()){
			lf[i]=fmaxs.back()+1;
		}
		else{
			lf[i]=1;
		}
		fmaxs.push_back(i);
		
	}
	for(int i=n;i>=1;i--){
		while(!bmaxs.empty()&&a[bmaxs.back()]<a[i]){
			bmaxs.pop_back();
		}
		if(!bmaxs.empty()){
			rg[i]=bmaxs.back()+1;
		}
		else{
			rg[i]=n;
		}
		bmaxs.push_back(i);
	}
	*/
	sort(a+1,a+n+1,greater<long long>());
	for(int i=1;i<n;i++){
		orgdiv[i]=a[i]-a[i+1];
	}
	for(int i=1;i<n;i++){
		totdiv[i]=totdiv[i-1]+orgdiv[i];
	}
	for(int i=n-1;i>=1;i--){
		sumdiv[i]=sumdiv[i+1]+orgdiv[i]*(n-i);
	}
	for(int i=1;i<=n;i++){
		int l=0,r=n-i,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(i,i+mid)){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		tans=max(tans,ans+1);
	}
	cout<<tans;
	return 0;
}
