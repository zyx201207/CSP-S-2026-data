#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,maxn=1,k=1;
long long a[1000001],b[1000001];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum=m;
		long long l=i-1,r=i+1;
		
		k=1;
		while(1){	
			long long al=abs(a[i]-a[l]),ar=abs(a[i]-a[r]);
			bool flag=true;
		 
			if((al<=ar&&l>=1&&sum-al>=0)){
				sum-=al;
				flag=false;
				l--;
				k++;
			}else if((flag&&r<=n&&sum-ar>=0)||(ar<=al&&r<=n&&sum-ar>=0)){
				sum-=ar;
				r++;
				k++;
			}else{
				break;
			}
		}
		
		maxn=max(maxn,k);	
	}
	cout<<maxn;
	return 0;

}
