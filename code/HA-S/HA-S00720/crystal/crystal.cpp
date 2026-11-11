#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag1=0,flag2=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			flag1=1; 
			break;
		}
	}
	for(int i=2;i<=n-1;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]){
			flag2=1; 
			break;
		}
	}
	if(flag1==1&&flag2==1){
		sort(a+1,a+1+n);
		for(int i=1;i<=n-1;i++){
			c[i]=a[i+1]-a[i];	
		}
		long long ans=0;
			for(int i=1;i<=n-ans;i++){
				long long sum=0,cnt=0;
				for(int j=i;j<=n&&sum<=m;j++){
					cnt++;
					sum+=c[j]*(j-i+1);
				}
				if(cnt>ans){
					ans=cnt;
				}	
			}
			cout<<ans;
	}else if(flag1==0){
		long long ans=1,sum=0;
		while(m>=sum){
			sum+=ans;
			ans++;
		}
		cout<<min(ans-1,n);
	}else if(flag2==0){
		long long ans=1,sum=0,len=a[2]-a[1];
		while(m>=sum){
			sum+=ans*len;
			ans++;
		}
		cout<<min(ans-1,n);
	}
	return 0;
}
