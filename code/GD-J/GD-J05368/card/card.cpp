#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[500005],c[5000005],d[500005],e[500005];

int main(){
	cin>>n>>m;
	for(int i=n;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int f=1;
		for(int j=1;j<=n;j++){
			c[a[j]]++;
			if(c[a[j]]>1){
				for(int k=d[a[j]];k<j;k++){
					b[f++]=a[k];
					a[k]=0;
					c[k]--;
				}
			}else{
				d[a[j]]=j;
			}
		}
		int num=0;
		for(int j=1;j<=n;j++){
			if(a[j]!=0){
				e[a[j]]++;
				num++;
			}
		}
		for(int j=n;j>0;j--){
			if(a[j]!=0 && a[j-1]==0){
				swap(a[j],a[j-1]);
			}
		}
		for(int j=1;j<=n;j++){
			a[++num]=b[j];
		}
		for(int j=n;j>0;j--){
			if(a[j]!=0 && a[j-1]==0){
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<e[i]<<" ";
	}
	return 0;
}
