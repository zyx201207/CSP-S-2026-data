#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int maxn=-1;
	for(int i=n-1;i>=0;i--){
		
		int k=m,ans=1;
		for(int j=i-1;j>=0;j--){
			if(k>=(a[i]-a[j])){k-=(a[i]-a[j]);ans++;}
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	return 0;
}
