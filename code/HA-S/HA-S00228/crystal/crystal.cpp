#include <bits/stdc++.h>
using namespace std;
long long n,nl[5005],m,zc,xj[5005],ans,zd=1,cha;
int main(){
	freopen("crystal.in ","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>nl[i];
		}
		sort(nl+1,nl+n+1);
		for(int i=1;i<=n;i++){
			zc=m;
			ans=1;
			for(int j=1;j<i;j++){
				xj[j]=nl[i]-nl[j];
				if(zc>=xj[j]){
					zc-=xj[j];
					ans++;	
				}
			}
			zd=max(ans,zd);
		}
		cout<<zd;
	}
	else{
		ans=1;
		cin>>nl[1]>>nl[2];
		cha=nl[2]-nl[1];
		for(int i=1;i<=n;i++){
			if(m>=i*cha){
				m-=i*cha;
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
