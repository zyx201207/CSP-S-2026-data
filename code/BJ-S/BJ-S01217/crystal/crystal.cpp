#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],d[500005];
bool cmp(int aa,int ba){
	return aa<ba;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	int mmax=-1;
	for(int i=1;i<=n;i++){
		long long sum=0;
		int j=i+1;
		bool f=0;
		for(;j<=n;j++){
			if(sum+d[j]*(j-i)>m){
				mmax=max(mmax,j-i);
				f=1;
				break;
			}
			else{
				sum+=d[j]*(j-i);
			}
		}
		if(f==0) mmax=max(mmax,j-i);
	}
	cout<<mmax;
	return 0;
}
