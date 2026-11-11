#include<bits/stdc++.h>
using namespace std;
long long a[500001],b[500001];
long long n,m,ans=1,cnt,sum=1e7;
int main(){
	freopen("crystal.in,r");
	freopen("crystal.out,r");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int i=2;i<=n;i++){
			if((a[i]-cnt)*ans<=m){
				ans++;
				cnt=a[i];
				m-=(a[i]-cnt)*ans;
			}
		}
		if(sum>ans) sum=ans;
	}
	cout<<sum;
			


	return 0;
}
