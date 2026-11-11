#include<bits/stdc++.h> 
using namespace std;
long long a[1000005],n,m,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=1,sum=a[1];
	while(l<=r&&r<=n){
		if(((r-l+1)*a[r]-sum)<=m){
			maxx=max(maxx,r-l+1);
			r++;
			sum+=a[r];
		}
		else{
			sum-=a[l++];
		}
	}
	cout<<maxx;
	return 0;
}
