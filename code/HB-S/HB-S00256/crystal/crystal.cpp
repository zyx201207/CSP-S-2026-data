#include<bits/stdc++.h>
using namespace std;
int n,ans=1,mid;
long long m;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]){
				mid=a[i];
				a[i]=a[j];
				a[j]=mid;
			}
		}
	}
	for(int i=n;i>1;i--){
		int k=i-1;
		int sum=1;
		int j=m;
		while(k>0){
			if(j>=(a[i]-a[k])){
				sum++;
				j=j-(a[i]-a[k]);
				
			}
			
		k--;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
