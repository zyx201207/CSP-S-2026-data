#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l,r,mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	l=1; r=n;
	while(l<r){
		mid=l+((r-l+1)>>1);
		bool flag=false;
		long long work=0;
		for(int i=1;i<=mid;i++)
		work+=abs(a[1+(mid>>1)]-a[i]);
		if(work<=m){
			l=mid;
			continue;
		}
		for(int i=2;i<=n-mid+1;i++){
			int ne=i+(mid>>1),ol=ne-1;
			work+=a[i-1]-2*a[ol]+a[i+mid-1]-(mid&1?a[ne]-a[ol]:0);
			if(work<=m){
				l=mid;
				flag=true;
				break;
			}
		}
		if(!flag)
		r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
