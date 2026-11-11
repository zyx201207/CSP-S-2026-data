#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int n,m,total,temp,ans,sim,last;
int a[N],arr[N];
int choice(int x){
	int l=1,r=x;
	while(r>l){
		int mid=(l+r-1)/2;
		//cout<<a[x]*(x-mid+1)<<" "<<arr[x]-arr[mid-1]<<endl;
		if(a[x]*(x-mid+1)-(arr[x]-arr[mid-1])<m){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	//cout<<l<<endl;
	return x-l+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		arr[i]=arr[i-1]+a[i];
	}
	ans=1;
	for(int i=1;i<=n;i++){
		temp=choice(i);
		ans=max(temp,ans);
	}
	cout<<ans;
	return 0;
} 
