#include<bits/stdc++.h>
using namespace std;
long long a[500005],f[500005],m,ans=1;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	bool fl=0,fg1=1;
	for(int i=2;i<=n;i++)
		if(a[i]==a[i-1]){
			fl=1;
			break;
		}
	for(int i=1;i<n;i++)
		f[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++)
		f[i]=f[i]*i;
	for(int i=1;i<n;i++)
		if(f[i]<=m)
			fg1=0;
	for(int i=1;i<n;i++){
		long long t=0,t1=0;
		for(int j=1;j<=i;j++){
			t+=f[j];
			t1++;
		} 
		if(t<=m)
			ans=max(t1,ans);
	}
	if(m==0 && !fl || n==1 || fg1){
		cout<<1;
		return 0;
	}
	cout<<ans+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
