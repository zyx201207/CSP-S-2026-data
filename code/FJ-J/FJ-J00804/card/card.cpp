#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],c[500005];
int b[300005],d[300005];
int main(){
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		int x=0;
		for(int i=1;i<=n;i++){
			b[i]=0;
			d[i]=0;
		}
		for(int i=k;i<=n;i++){
			b[a[i]]++;
			if(b[a[i]]==2){
				x=d[a[i]]-1;
				for(int j=1;j<=m;j++){
					if(d[j]>=d[a[i]]){
						d[j]=0;
						b[j]=0;
					}
				}
				b[a[i]]=1;
			}
			d[a[i]]=++x;
		}
		for(int i=1;i<=m;i++){
			if(b[i]!=0){
				c[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}

