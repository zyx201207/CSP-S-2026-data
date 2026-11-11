#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		d[i]=(a[i]-a[i-1])*(i-1)+d[i-1];
	}
	int mx=1;
	int s=1;
	for(int i=2;i<=n;i++){
		if(d[i]<=m){
			s=i+1;
			mx=i;
		}
	}
	for(int i=s;i<=n;i++){
		int l=1,r=i-1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(d[i]-d[mid]-(a[i]-a[mid])*mid>m){
				l=mid;
			}else{
				r=mid;
			}
		}
		mx=max(mx,i-r);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
