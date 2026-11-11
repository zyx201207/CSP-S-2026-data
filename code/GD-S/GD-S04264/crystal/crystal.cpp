#include<bits/stdc++.h>
using namespace std;
    int n,ans=0;
	long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n+10],b[n+10]={0};
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	b[i]=a[i]-a[i-1]; 
	for(int i=1;i<=n;i++){
		long long p=m;
		int q=0;
		for(int j=1;j<n;j++){
			if(p>=b[j]*j){
				p-=b[j];
				q++;
				ans=max(ans,q);
			}
		} 
}
	cout<<ans+1;
}
