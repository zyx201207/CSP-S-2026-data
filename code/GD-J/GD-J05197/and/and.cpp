#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005],cnt,ans,j;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=m;i<=n;i++){
		j=i-m+1;
			cnt=a[j];
			for(int k=1;k<m;k++){
				cnt=cnt&a[j+k];
			}
			ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
