#include<bits/stdc++.h>
using namespace std;
int n,m,s=0;
int a[500001],b[500001],c[500001],d[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=1;j<=m;j++){
			b[j]=0;
			d[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				d[++s]=a[j];
				b[a[j]]=s;
			}else{
				for(int k=b[a[j]]+1;k<=s;k++){
					b[a[k]]=0;
				}
				s=b[a[j]];
			}
		}
		for(int j=1;j<=s;j++){
			c[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
