#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[600000];
ll b[600000];
int num;
ll sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
//	if((a[n]-a[1])/n==a[n]-a[n-1]&&(a[n]-a[1])/n==a[n-1]-a[n-2]&&(a[n]-a[1])/n==a[n-2]-a[n-3]&&(a[n]-a[1])/n==a[n-3]-a[n-4]&&(a[n]-a[1])/n==a[n-4]-a[n-5]){
//		cout<<m/((a[n]-a[1])/n);
//	}	
	for(int i=1;i<=n;i++){
		b[i]=(a[i]-a[i-1])*(i-1)+b[i-1];
	}
	
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[j]-((a[j]-a[i-1])*(i-1)+b[i])<=m){
				num=max(num,j-i+1);
			}
		}
	}cout<<num;
	return 0;
} 
