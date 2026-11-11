#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,a[500001],sum,x,max1=1,s,c,cnt=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++) sum+=(a[i]-a[1]);
	if(sum<=m){
		cout<<n;
		return 0;
	}
	s=a[2]-a[1];
	for(i=2;i<n;i++) if(a[i+1]-a[i]==s) c++;
	if(c+2==n){
		c=m/s;
		while(c>=0){
			c-=cnt;
			cnt++;
			x++;
		}
		cout<<x;
		return 0;
	}
	sum=0;
	for(i=2;i<=n;i++){
		sum=0,x=1,j=i;
		while(j>1&&sum+a[i]-a[j-1]<=m) sum+=(a[i]-a[j-1]),j--,x++;
		max1=max(max1,x);
	}
	cout<<max1;
	return 0;
}