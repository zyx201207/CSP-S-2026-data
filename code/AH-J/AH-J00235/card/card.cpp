#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll i,j,n,m,a[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		ll p[201000]={0};
		for(i=1;i<=n;i++){
			ll k,l=0,t[101000]={0};
			for(j=i;j<=n;j++){
				l++;
				t[l]=a[j];
				for(k=1;k<l;k++){
					if(t[k]==t[l]){
						while(l>k){
							l--;
						}
					}
				}
			}
			for(j=1;j<=l;j++){
				p[t[j]]++;
			}
		}
		for(i=1;i<=m;i++){
			cout<<p[i]<<" ";
		}
	}else{
		ll p[201000]={0};
		for(i=1;i<=n;i++){
			ll l=0,t[101000]={0};
			for(j=i;j<=n;j++){
				t[l]=a[j];
				l++;
				if(t[l-1]==a[j]){
					l--;
				}
			}
			for(j=1;j<=l;j++){
				p[t[j]]++;
			}
		}
		for(i=1;i<=m;i++){
			cout<<p[i]<<" ";
		}
	}
	return 0;
}
