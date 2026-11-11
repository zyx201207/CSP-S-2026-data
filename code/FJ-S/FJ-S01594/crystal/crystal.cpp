#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m,a[500009]={};
	cin>>n>>m;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	long long k=sum/n;
	long long min_=1000000000000,f,b;
	for(int i=1;i<=n;i++){
		if(a[i]-k<min_){
			min_=abs(a[i]-k);
			f=a[i];
			b=i;
		}
	}
	long long ans=1,l=b-1,r=b+1;
	while(m>0&&l>=1&&r<=n){
		if(f-a[l]>=a[r]-f){
			m-=a[r]-f;
			r++;
		}
		else if(f-a[l]<a[r]-f){
			m-=f-a[l];
			l--;
		}
		if(m>=0){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
