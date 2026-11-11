#include<bits/stdc++.h>
using namespace std;
int n,m,maxa=0,a[2^30+1]={0};
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxa=max(maxa,a[i]);
		}
		cout<<maxa;
		return 0;
	}
	if(m==n){
		maxa=a[1];
		for(int i=2;i<=n;i++){
			maxa=char(maxa)&char(a[i]);
		}
		cout<<maxa;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i;j<=n;j++){
				maxa=max(maxa,(char(a[j])&char(a[i])));
			}
		}
		cout<<maxa;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n-2;i++){
			for(int j=i;j<=n-1;j++){
				for(int x=j;x<=n;x++){
					maxa=max(maxa,(char(a[j])&char(a[i])&char(a[x])));
				}
			}
		}
		cout<<maxa;
		return 0;
	}
	return 0;
}
