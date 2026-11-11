#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long mx=-1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long sum=0;
		for(int j=i;j>=1;j--){
			if(sum+a[i]-a[j]<=m){
				sum+=a[i]-a[j];
			}
			else{
				mx=max(mx,(long long)(i-j));
				break;
			}
			if(j==1){
				mx=max(mx,(long long) i);
			}
		}
	}
	cout<<mx;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
