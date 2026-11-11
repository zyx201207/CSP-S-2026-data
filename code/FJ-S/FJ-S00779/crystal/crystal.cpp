#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int fla=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) fla=0;
	}
	sort(a+1,a+1+n);
	if(fla){
		long long nw=0;
		while(m-nw*(a[2]-a[1])>=0){
			m-=nw*(a[2]-a[1]);
			nw++;
		}
		cout<<nw;
	}
	else{
		long long maxx=0;
		for(int i=1;i<=n;i++){
			long long nw=1,t=m;
			while(t>0&&i+nw<=n){
				if(t>=nw*(a[i+nw]-a[i+nw-1])){
					t-=nw*(a[i+nw]-a[i+nw-1]);
					nw++;
				}else{
					t=0;
				}
			}
			while(a[i+nw]==a[i+nw-1]&&i+nw<=n) nw++;
			maxx=max(maxx,nw);
			if(i+nw==n) break;
		}
		cout<<maxx;
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
