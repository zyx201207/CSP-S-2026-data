#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans,f=1,a[500001];
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1 && a[i]!=a[i-1]) f=0;
	}
	if(f==1){
		for(int i=0;1;i++){
			if(sum+i>m) break;
			sum+=i;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	long long i,la,l=1,r=n,mid;
	while(l<r){
		la=sum;
		sum=0;
		mid=(l+r+1)/2;
		for(i=1;a[i]<=a[mid];i++){
			sum+=a[mid]-a[i];
		}
		
		if(sum<m) l=mid+1;
		else if(sum==m){
			cout<<i;
			return 0;
		}
		else r=mid-1;
	}
	do{
		sum=0;
		for(i=1;a[i]<=a[l];i++){
			sum+=a[l]-a[i];
		}
		l--;
	}while(sum>m);
	cout<<i-1<<endl;
	return 0;
} 
