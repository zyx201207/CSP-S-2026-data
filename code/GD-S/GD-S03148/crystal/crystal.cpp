#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n); 
	b[0]=0;
	for(int i=1;i<n;i++) b[i]=a[i-1]+b[i-1];
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i-ans;j>=0;j--){
			long long c=a[i]*(i-j)-b[i]+b[j];
			if(c<=m){
				ans=max(ans,i-j);
			}
			else break;
		}
	}
	cout<<ans+1;
	return 0;
} 
