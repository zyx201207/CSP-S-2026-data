#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005]={},ans=0,sum=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;i>=1;i--){
		if(ans&a[i]!=0){
			ans=ans&a[i];
			sum++;
		}else{
			for(int j=i+1;j>=1;j--){
				if(ans&a[i]!=0){
					ans=ans&a[i];
					i=j;
					sum++;
					j=0;
				}
			}
		}
		if(sum==m) break;
		if(ans==0) break;
	}
	cout<<ans;
	return 0;
}
