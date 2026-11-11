#include<bits/stdc++.h>
using namespace std;
long long a[2100000],dp[2100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,s=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n;i++){
			if(a[i]-a[0]<=d){
				dp[i]=1;
				continue;
			}
			int h=lower_bound(a,a+i,a[i]-d)-a,mi=INT_MAX,p=0;
			for(int j=h;j<=i;j++){
				if(mi>a[i]){
					mi=a[i];
					p=0;
				}else if(mi==a[i]){
					p++;
				}
			}
			if(p==2){s++;}
			dp[i]=mi+1;
		}
		cout<<s<<endl;
	}
	return 0;
}

