#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],z=1,c;
long long check(long long p,long long k){
	int x=1,l=p-1,r=p+1;
	if(l==0)l=1;
	if(r==n+1)r=n;
	while(k>=0){
		if(a[p]-a[l]<=a[r]-a[p]){
			if(l-1>=1){
				k-=(a[p]-a[l]);
				l--;
				x++;
			}else if(r+1<=n){
				k-=a[r]-a[p];
				r++;
				x++;
			}else{
				break;
			}
		}else{
			if(r+1<=n){
				k-=a[r]-a[p];
				r++;
				x++;
			}else if(l-1>=1){
				k-=(a[p]-a[l]);
				l--;
				x++;
			}else{
				break;
			}
		}
	}
	return x-1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[2]-a[1])c=1;
	}
	sort(a+1,a+n+1);
	if(c==0){
		int u=a[2]-a[1];
		int k=u;
		while(m-u>=0&&z<n){
			m-=u;
			u+=k;
			z++;
		}
	}else{
		for(int i=1;i<=n;i++){
			z=max(z,check(i,m));
		}
	}
	cout<<z;
	return 0;
}
