#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005];
int ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)f[i]=a[i]-a[i-1];
	int end=1;
	for(int i=2;i<=n;i++){
		if(m>=f[i]*(i-end)){
			ans=max(ans,i-end+1);
			m-=f[i]*(i-end);
			continue;
		}
		else{
		 while(m<f[i]*(i-end)&&i>end){
			m+=a[i-1]-a[end];
			end++;
		}
		if(i==end){
			i++;
			end++;
			continue;
		}
		m-=f[i]*(i-end);
		ans=max(ans,i-end);
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
