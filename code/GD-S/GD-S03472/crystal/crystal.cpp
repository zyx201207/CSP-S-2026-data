#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=1;
long long arr[N];
unsigned long long a[N],m;
unsigned long long sum=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<n;i++){
		arr[i]=arr[i+1]-arr[i];
	}
	arr[n]=a[n]=0;
	for(int i=n-1;i>=1;i--){
		a[i]=arr[i]+a[i+1];
	}
	for(int i=n,j=n;i>=1;i--){ 
		if(j>i){
			j=i;
			sum=0;
		}
		while((j>=1)&&(sum+(a[j-1]-a[i])<=m)){
			sum+=(a[j-1]-a[i]);
			j--;
		}
		int len=i-j;
		ans=max(ans,len);
		if(j==0){
			break;
		}
		sum-=len*(a[i-1]-a[i]);
	}
	cout<<ans;
	return 0;
} 
