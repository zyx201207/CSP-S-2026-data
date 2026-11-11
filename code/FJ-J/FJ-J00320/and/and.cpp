#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
long long c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long s=0;
	int cnt=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long z;
		cin>>z;
		b[i]=z;
		for(int j=1;j<=31;j++){
			s=10*s+z%2;
		    z/=2;
		}
		for(int j=31;j>=1;j--){
			a[i]=a[i]*10+s%10;
			s/=10;
		}
	}
	for(int i=1;i<=n;i++){
		c[i]=a[i];
	}
	for(int i=1;i<=31;i++){
		for(int j=1;j<=n;j++){
			if(a[j]/10^(i-1)==1 && a[j]==c[j]){
				cnt++;
				ans+=b[j];
				c[j]=a[j];
			}
		}
		if(cnt==m){
			cout<<ans;
			return 0;
		}
		else if(cnt>m){
			for(int k=1;k<=n;k++){
				c[k]==-1;
			}
		}
		ans=0;
	}
}
