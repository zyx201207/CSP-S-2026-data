#include<bits/stdc++.h>
using namespace std;
long long ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	if(m==0){
		cout<<0;
		return 0;
	}
	long long a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long k=0,tmp=m;
		for(int j=i-1;j>=1;j--){
			if(tmp<0)break;
			if(a[i]==a[j])k++;
			else if(a[i]-a[j]<=tmp){
				k++;
				tmp-=a[i]-a[j];
			}
		}
		ans=max(ans,k);
	}
	cout<<ans+1;
	return 0;
}
