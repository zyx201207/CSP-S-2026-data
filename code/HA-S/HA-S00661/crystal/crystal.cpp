#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],l,r,mid,sum=-1;//sum是一共的水晶 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	l=1;
	r=n;
	while(l<=r){
		mid=(l+r)/2;
		long long w=m,ww=m;
		long long s=0;
		for(int i=mid;i>=1;i--){
			if(a[mid]-a[i]<=w){
				w-=(a[mid]-a[i]);
				s++; 
			}else{
				w=0;
				w-=(a[mid]-a[i]);
			}
		}if(sum<s)sum=s;
		if(w>=0){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}cout<<sum;
	return 0;
} 
