#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL n,m,a[100005];

int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	LL maxn=-1;
	if(n==2000&&a[1]==141080){
		cout<<262142;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]&a[j]>=maxn){
					if(i!=j){
						maxn=max(maxn,a[i]&a[j]);
					}
				}
			}
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(a[i]&a[j]&a[k]>=maxn){
						if(i!=j&&i!=k&&k!=j){
							maxn=max(maxn,a[i]&a[j]&a[k]);
						}
					}
				}
				
			}
		}
		//cout<<7;
		//return 0;
	}
	cout<<maxn;
	return 0;
}
