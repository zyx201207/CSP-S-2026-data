#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,pj=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		pj+=a[i];
	}
	pj/=n;
	//cout<<pj;
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		if(a[i]!=pj&&a[i]<pj&&m>0){
			if(m>=(pj-a[i])){
				a[i]=pj;
				m-=(pj-a[i]);
			}
		}
		if(a[i]==pj){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
