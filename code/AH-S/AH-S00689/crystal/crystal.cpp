#include<bits/stdc++.h>
using namespace std;

long long n,l=1,sum=1;
long long m,a[500005],c[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		c[i]=a[i]+c[i-1];
	}
	for(long long r=1;r<=n;r++){
		//cout<<l<<" "<<r<<" "<<(r-l+1)*a[r]<<" "<<c[r]<<" "<<c[l-1]<<endl;
		//cout<<(r-l+1)*a[r]-c[r]+c[l+1]<<endl;
		if((r-l+1)*a[r]-c[r]+c[l-1]>m){
			l++;
			for(;l<=r;l++)	
				if((r-l+1)*a[r]-c[r]+c[l-1]<=m)
					break;
		}
		sum=max(sum,r-l+1);
		//cout<<sum<<" "<<endl<<endl;
	}
	cout<<sum;
	return 0;
}
