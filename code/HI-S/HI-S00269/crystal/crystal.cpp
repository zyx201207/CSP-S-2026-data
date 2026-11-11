#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	long long n,m;
	long a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout<<1;return 0;
	}if(n==2){
		cout<<(a[2]>m?1:2);return 0;
	}
	for(int i=n;i>1;i--){
		a[i]=a[i]-a[i-1];
	}
	long long sum=0;
	int ans=1;
	int i=1,j=2;
	long long d=0;
	while(j<=n){
		if(sum<=m&&sum+a[j]*(j-i)<=m){
			sum+=a[j]*(j-i);
			d+=a[j];
			j++;
		}else{
			ans=max(ans,j-i);
			sum-=d;
			d-=a[++i];
		}
	}
	if(sum>m)ans=max(ans,j-i);
	cout<<ans;
} 
