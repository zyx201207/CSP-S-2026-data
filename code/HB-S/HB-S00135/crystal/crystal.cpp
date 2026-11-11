#include <bits/stdc++.h>
using namespace std;
long long n,m,sum,a[500005],c[500005];
bool cmp(long long x,long long y){
	return x<y;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=1;i<n;i++){
		c[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		long long x=m;
		long long ans=1;
		for(int j=i;j<n;j++){
			if(x>=(c[j]*ans)){
				ans++;
				x-=c[j]*ans;
			}
		}
		sum=max(sum,ans);
	}
	cout <<sum;
	return 0;
}
