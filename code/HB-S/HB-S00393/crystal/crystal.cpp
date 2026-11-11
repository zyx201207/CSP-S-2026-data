#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005],c[500005];
int ans=0;
void dfs(int x,int cnt,int l,int b){
	if(x==n+1||cnt==n||b<a[x+1]){
		ans=max(ans,cnt);
		//cout<<"basic:"<<b<<"cnt:"<<cnt<<endl;
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(b-a[i]<=l&&b>=a[i]){
			dfs(i,cnt+1,l-b+a[i],b);
		}
	}
	return;
}
long long erf(){
	long long l=1,r=n-1;
	while(l<r){
		long long mid=(l+r)/2;
		if((mid*mid+mid)/2<l){
			r=mid-1;
		}else if((mid*mid+mid)/2>l){
			l=mid+1;
		}else{
			return mid;
		}
	
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=0;
	}
	if(f==1){
		cout<<erf()+1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(0,0,m,a[i]);
	
	}
	cout<<ans;
	return 0;
}
