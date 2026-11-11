#include<bits/stdc++.h>
using namespace std;
#define int long long
long long a[500005];
long long pre[500005];
long long n,m;
int mx=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		pre[i]+=pre[i-1];
		pre[i]+=(a[i]-a[i-1])*(i-1);
	}
	/*
	for(int i=1;i<=n;i++){
		cout<<pre[i]<<" ";
	}
	*/
	for(int i=n;i>=1;i--){
		int l=1,r=i;
		while(l<r){

			int mid=(l+r)/2;	
			int x=pre[i]-(mid-1)*(a[i]-a[mid])-pre[mid];
			if(x<=m){
				mx=max(mx,i-mid+1);
				r=mid;
			}
			else{
				l=mid+1;
			}	
		//	cout<<"preµÚ"<<i<<":"<<pre[i]<<" preµÚ"<<mid<<":"<<pre[mid]<<" max:"<<mx<<" ²î£º"<<x<<" "<<m<<endl;
	
	}}
	cout<<mx;
	return 0;
}
