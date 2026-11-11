#include<bits/stdc++.h>
using namespace std;
int m,n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int shu[m+2];
	for(int i=1;i<=n;i++) {
		int tu=1;
		int r[n+2]={};
		for(int j=i;j<=n;j++){
			bool p=0;
			int jh;
			for(int k=1;k<=tu;k++){
				if(a[j]=r[k]){
					p=1;
					jh=k;
				}
				if(p){
					r[k]=0;
				}
			}
			if(p){
				tu=jh;
			}
			r[tu]=a[j];
			tu++;
		}
		for(int j=1;j<=n;j++){
			for(long long k=1;k<=n;k++){
				if(j==r[k]){
					shu[j]++;
					k=99999999999;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<shu[i];
	}
	return 0;
}
