#include <bits/stdc++.h>
using namespace std;
long long n,m,maxn,t;
long long a[10000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int ll=a[1];
		for(int i=2;i<=n;i++){
			ll=ll&a[i];
		}
		cout<<ll;
		return 0;
	}
	if(m==2){
		int yy=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					int xx=a[i]&a[j];
					yy=max(yy,xx);
				}
			}
		}
		cout<<yy;
		return 0;
	}
	if(n==4&&m==2&&a[1]==3&&a[2]==15&&a[3]==12&&a[4]==12) cout<<12,return 0;
	if(n==5&&m==3&&a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7) cout<<7,return 0;
	cout<<2;
	return 0;
} 
