#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,ma;
long long a[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+a[i];
	} 
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid)*(a[i]-a[i-1])-(a[i-1]-a[mid-1])>m){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		ma=max(ma,i-l+1);
	}
	cout<<ma;
	return 0;
}
