#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans=0;
void d(int x,int j,long long b){
	if(x==0){
		ans=max(b,ans);
	}
	for(int i=j;i<=n;i++)
		d(x-1,i,b&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int k=1;k<=n;k++){
		d(m-1,k,a[k]);
	}
	cout<<ans;
	return 0;
} 
