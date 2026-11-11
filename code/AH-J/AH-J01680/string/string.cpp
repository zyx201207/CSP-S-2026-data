#include"bits/stdc++.h"
#define int long long
using namespace std;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int ans=0;
	int l=1,r=n;
	while(l<r){
		if(a[l]>a[r]){
			if(c[l]!=c[r])
				ans+=a[r];
			a[l]-=a[r];
			r--;	
		}
		else if(a[l]<a[r]){
			if(c[l]!=c[r])
				ans+=a[l];
			a[r]-=a[l];
			l++; 
		} 
		else {
			if(c[l]!=c[r])
				ans+=a[r];
			l++;
			r--;
		}
	} 
	printf("%lld\n",ans);
	return 0;
}
//AH-J01680
//8:30-12:00
/*
5
1 a
1 b
1 a
1 b
1 a
ababa 
*/
