#include<bits/stdc++.h> 
using namespace std;
long long ans=0,sum=0,t=0;
long long n,m,a[100005];
long long k;
int main(){
	freopen("crystal.in","w",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=1;i<n;i++){
	 ans=0,sum=0,t=0;
		for(int j=i-1;j>=0;j--){
			k-=a[i]-a[j];
			while(k<0){
				k++;
				sum++;
			}
			if(sum<=m){
				t++;
			}else break;
		}
		if(t>ans){
			ans=t;
		}
	}
	cout<<ans+2;
	return 0;
}
