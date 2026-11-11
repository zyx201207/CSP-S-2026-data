#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans=0;
int a[N],d[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[n];
	for(int j=1;j<=n;j++)d[1]=a[j];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			d[j]=max(d[j],d[j-1]&a[i]);
		}
	}
	int ans=INT_MIN;
	for(int i=1;i<=m;i++)ans=max(ans,d[i]);
	cout<<ans;
	return 0;
} 
