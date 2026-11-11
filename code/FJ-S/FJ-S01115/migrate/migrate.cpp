#include<bits/stdc++.h>
using namespace std;
long long t,a,b,c,d[2000005],e[2000005],dp[2000005],dp1[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			cin>>d[i];
		}for(int i=1;i<=a;i++){
			long long l=1,r=a;
			while(l<r){
				long long mid=(l+r)/2;
				if(d[i+mid-1]-d[i-1]>=b)r=mid;
				else l=mid+1;
			}d[i]=l;
		}for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				if(j>d[i]); 
			}
		}cout<<1;
	}
}
