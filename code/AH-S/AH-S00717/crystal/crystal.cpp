#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,sum[500005];
int f(int l,int r){
	while(l<r){
		int mid=(l+r)/2;
		int q=0;
		for(int i=1;i<=n-mid+1;i++){
			int sumn=sum[mid+i-1]-sum[mid-1];
			if((sumn+m)>=a[i+mid-1]*mid){
				q=1;
			}
		}
		if(q==1){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
		cout<<l<<' '<<mid<<' '<<r<<' '<<q<<endl;
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int u=a[1];
	for(int i=1;i<=n;i++){
		a[i]-=u;
		sum[i]=sum[i-1]+a[i];
	}
	if(n<=30000){  
		for(int i=n;i>=1;i--){
			for(int j=1;j<=n+1-i;j++){
				int sumn=sum[j+i-1]-sum[j-1];
				if((sumn+m)/i>=a[j+i-1]){
					cout<<i;
					return 0;
				}
			}
		}
	}
	else{
		cout<<f(1,n);
	}
    return 0;
}
