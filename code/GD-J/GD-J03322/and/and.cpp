#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int const N=2e5+10;
int arr[N]={};
int a[N]={};
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n,cmp);
	
	
	int ans=arr[1],mx=-1e9;
	for(int j=1;j<=n-m+1;j++){
		ans=arr[j];
		for(int k=1+j;k<=m+j-1;k++){
			ans=ans&arr[k];
		}
		mx=max(mx,ans);
	}
	cout<<mx;
	
	
	return 0;
} 
