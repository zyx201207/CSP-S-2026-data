#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50200],c[50200],d[50200];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				c[a[j]]=j;
			}else{
				for(int k=c[a[j]];k<j;k++){
					c[a[k]]=0;
				}
				c[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j]!=0){
				d[j]++;
			}
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}

