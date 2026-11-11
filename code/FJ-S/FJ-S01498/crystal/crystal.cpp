#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int j=a[n];j>=a[1];j--){
		long long cnt=0,ma=m;
		int id=upper_bound(a+1,a+n+1,j)-a;
		if(a[id]!=j)id--;
		for(int i=id;i>=1;i--){
			if(ma>=j-a[i]){cnt++;ma-=(j-a[i]);}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
