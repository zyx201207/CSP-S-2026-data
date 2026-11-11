//GZ-S00129   遵义市第四中学   陈律金
#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int a[N];
long long k[N];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)k[i]=k[i-1]+a[i];
	int ma=-1;
	for(int i=n;i>0;--i){
		int l=0,r=i,maxx=-1;
		while(l<=r){
			int mid=l+(r-l)/2;
			if((i-mid)*a[i]-k[i]+k[mid]>m)l=mid+1;
			else{
				r=mid-1;
				maxx=max(maxx,i-mid);
			}
		}
		ma=max(ma,maxx);
	}
	cout<<ma;
	return 0;
}
