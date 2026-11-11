#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int fla=1,fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) fla=0;
		long long s=a[i];
		long long t=2;
		while(t<s+1){
			t*=2;
		}
		if(t!=s+1) fl=0;
	}
	int f=0;
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		f=1;
	}
	if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max((a[i]&a[j]),ans);
			}
		}
		f=1;
		cout<<ans;
	}
	if(m==n&&f==0){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		f=1;
		cout<<ans;
	}
	if(fla==1&&f==0){
		cout<<n-m;
		f=1;
	}
	if(fl==1&&f==0){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		f=1;
	}
	if(f==0){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0;
} 
