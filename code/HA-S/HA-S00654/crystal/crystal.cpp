#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
				int sum=0;
			for(int j=i;j>=1;j--){
				if(sum+a[i]-a[j]<=m&&i-j>maxx){
					maxx=i-j;
				}else if(sum+a[i]-a[j]>m) break;
				sum+=a[i]-a[j];
			}
		}
		cout<<maxx+1;
	}else{
		for(int i=n/2;i>=1;i--){
			if(a[n/2+1]-a[i]<=m){
				m-=a[n/2+1]-a[i];
			}else{
				cout<<n/2+1-i;
			}
		}
	}
	return 0;
}
