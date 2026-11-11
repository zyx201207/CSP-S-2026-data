#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1 ; i<=n ; i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n ; i>=2 ; i--){
		if(i<=sum){
			cout<<sum;
			return 0;
		}
		long long k=m,ans=i,q=0;
		while(k>=1&&ans>=1){
			if(a[i]-a[ans]<=k){
				k=k-(a[i]-a[ans]);
				q++;
			}else{
				k=-1;
			}
			ans--;
		}
		sum=max(sum,q);
	}
	cout<<sum;
	return 0;
}
