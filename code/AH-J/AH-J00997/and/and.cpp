#include<bits/stdc++.h>
using namespace std;
int m,cnt1=0,maxnn=-1,n,maxn=-1,chen_zhe=-1;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(m==1){cout<<maxn;return 0;}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxnn=max(maxnn,a[i]&a[j]);
			}
		}
		cout<<maxnn;
		return 0;
	}
	long long cnt=0,ans=0;
	if(m==n){
		for(int i=1;i<=n;i++){
			cnt+=a[i]&a[i+1];
		}
		cout<<cnt;
		return 0;
	}
	long long kkksc03=0,kkksc04=0,sola=0;
	if(m==n-1){
		for(int i=1;i<=n-1;i++){
			kkksc03+=a[i]&a[i+1];
		}
		for(int i=2;i<=n;i++){
			kkksc04+=a[i]&a[i+1];
		}
		sola=max(kkksc03,kkksc04);
		cout<<sola;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
		    for(int j=i+1;j<=n;j++){
			    for(int k=j+1;k<=n;k++){
				    chen_zhe=max(chen_zhe,a[i]&a[j]&a[k]);
			    }
		    }
	    }
	    cout<<chen_zhe;
	    return 0;
	}
	return 0;
}
