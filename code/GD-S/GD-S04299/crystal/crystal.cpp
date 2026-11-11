#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
long long a[maxn],d[maxn];
int main(){
	memset(d,0,sizeof(d));
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=0;
	long long sam=0;
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(d[i]==d[1]){
			sam++;
		}
	}
	if(sam==n){
		long long num=m;
		while(num>=0){
			ans++;
			num-=d[1]*ans;
		}
	}
	else{
		for(int i=0;i<n;i++){
			long long num=m,sum=1,he=0;
			for(int j=n-i;j>1;j--){
				he+=d[j];
				num-=he;
				if(num<0){
					break;
				}
				sum++;
				ans=max(ans,sum);
			}
		}
	}
	cout<<ans;
	return 0;
} 
