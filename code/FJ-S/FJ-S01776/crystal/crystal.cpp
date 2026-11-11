#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],c[N],s[N],ss[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("gen.in","r",stdin);
//	freopen("std.out","w",stdout);
	cin >> n >> m;
//	bool flagA=1,flagB=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
//		if(a[i]!=i)flagA=0;
//		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=2)flagB=0;
	}
//	if(flagA){
//		for(int i=1;i<n;i++){
//			if(m-i>=0){
//				m-=i;
//				ans++;
//			}else{
//				break;
//			}
//		}
//		cout<<ans;
//		return 0;
//	}
//	if(flagB){
//		int cha=a[2]-a[1];
//		for(int i=1;i<n;i++){
//			if(m-(i*cha)>=0){
//				m-=i*cha;
//				ans++;
//			}else{
//				break;
//			}
//		}
//		cout<<ans;
//		return 0;
//	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)c[i]=a[i+1]-a[i];
	for(int i=n-1;i>=1;i--)s[i]=s[i+1]+c[i];
	for(int i=n-1;i>=1;i--)ss[i]=ss[i+1]+s[i];
	for(long long i=1;i<=n;i++){
		long long l=1,r=i,mid=(l+r)/2;
		while(l<r){
			mid=(l+r)/2;
			int x=(ss[mid]-ss[i])-(i-mid)*s[i];
			//cout<<mid<<" "<<x<<"\n";
			if(x>m)l=mid+1;
			else if(x<m)r=mid;
			else{
				l=mid;
				break;
			}
		}
		ans=max(ans,i-l+1ll);
	}
	cout<<ans;
	return 0;
} 
