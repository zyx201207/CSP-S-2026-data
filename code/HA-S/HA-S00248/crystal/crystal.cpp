#include<bits/stdc++.h>
using namespace std;
int n,jj=0,g=0;
long long a[500009],m,mmax=-1,f,ans=0,x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int xx=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=xx){
			jj=1;
		}
	}
	if(jj==0){
		while(1){
			if(m-g*xx>=0){
				ans++;
				g++;
				m=m-g*xx;
			}else{
				cout<<ans;
				return 0;
			}
		}
	}
	f=m;
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=i;j>=1;j--){
			if(a[i]==a[j]){
				ans++;
			}else{
				if(m-(a[i]-a[j])>=0){
					ans++;
					m-=a[i]-a[j];
				}
			}
		}
		mmax=max(ans,mmax);
		m=f;
	}
	cout<<mmax;
	return 0;
}
