#include<bits/stdc++.h>

using namespace std;

long long n,m,d[500010],f[500010],ans=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&d[i]);
	}sort(d+1,d+n+1);
	for(int i=1;i<=n;i++)f[i]=f[i-1]+d[i];
	long long l=1,r=1;
	while(r<=n){
		r++;
		if(d[r]*(r-l+1)-(f[r]-f[l-1])<=m){
			ans=max(ans,r-l+1);
			//cout<<'r'<<l<<' '<<r<<endl;
		}else{
			while(d[r]*(r-l+1)-(f[r]-f[l-1])>m){
				l++;
			}
			//cout<<'l'<<l<<' '<<r<<endl;
		}
	}cout<<ans;
	return 0;
}

