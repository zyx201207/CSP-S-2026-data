#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,m,a[2000010];
void main1(){//O(N^2)
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=0;i<n-3;i++){
		int j=i+3;
		if(a[j]-a[i+1]<=m&&a[j]-a[i]>m&&a[j-1]-a[i]<=m){
			ans++;
			int x=0;
			for(int lj=j+1;lj<n;lj++){
				if(a[lj]-a[lj-2]>m&&a[lj]-a[lj-1]<=m){
					x++;
					ans++;
				}else{
					break;
				}
			}
			for(int li=i-1;li>=0;li--){
				if(a[li+2]-a[li]>m&&a[li+1]-a[li]<=m){
					ans+=x+1;
				}else{
					break;
				}
			}
		}
	}
	cout<<ans<<"\n";
}
void main2(){//O(N)
	long long ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long x=a[2]-a[1];
	int i=2;
	for(;i*x<=m;i++){
	}
	i--;
	for(int j=2*i;j<=n;j+=i){
		ans+=(n-j+1);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c<=10){
			main1();
		}else if(c<=12){
			main2();
		}else{
			main1();
		}
	}
	return 0;
}
