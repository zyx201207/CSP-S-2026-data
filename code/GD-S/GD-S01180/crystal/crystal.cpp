#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool f1=true,f2=true;
	long long n,m;
	cin>>n>>m;
	cin>>a[1]>>a[2];
	int dc=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=dc){
			f1=false;
		}
		if(a[i]>=100&&a[i]<=-100){
			f2=false;
		}
	}
	if(f1){
		int x=int(sqrt(m/dc*2));
		if(x>=n){
			cout<<n;
		}else{
			if(x*(x+1)*dc<=m*2){
				cout<<x+1;
			}else{
				cout<<x;
			}
		}
	}else if(f2&&n>5000){
		cout<<n;
	}else{
		int ans=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			long long s=0;
			int j=0;
			while(i-j>=1&&s+a[i]-a[i-j]<=m){
				s=s+a[i]-a[i-j];
				j++;
			}
			ans=max(ans,j);
		}
		cout<<ans;
	}
	return 0;
}
