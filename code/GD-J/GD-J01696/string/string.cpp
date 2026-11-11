#include<bits/stdc++.h>
#define int long long
using namespace std;
int l,r,n,p[200005],ans;
char a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++)cin>>p[i]>>a[i];
	l=1,r=n;
	int ls=p[l],rs=p[r];
	while(l<r){
		while(ls>=rs){
			if(a[l]!=a[r]){
				ans+=p[r];
				
			}
			if(ls<rs+p[r-1]&&a[l]!=a[r]&&rs!=ls){
				ans+=rs+p[r-1]-ls;
			}
			r--;
			rs+=p[r];
		}
		l++;
		ls+=p[l];
	}
	cout<<ans;
	return 0;
}
