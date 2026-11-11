#include<bits/stdc++.h>
using namespace std;
long long a[550000],b[550000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	long long tmp=a[1];
	for(int i=1;i<=n;i++){
		a[i]-=tmp;
		b[i]=a[i]+b[i-1];
	}
	b[0]=a[0]=0;
	long long l=1,r=1,ans=0;
	while(l<=r&&r<=n){
		long long len=r-l+1;
		if(a[r]*len-b[r]+b[l-1]>m){
			l++;
		}else{
			ans=max(ans,len);
			r++;
		}
	}
	cout<<ans;
	return 0;
}
