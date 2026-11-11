//GZ-J00378,贵阳市中天中学，郑景元 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[50010],b[50010],c[50010],d[50010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[j]=a[j];
			b[c[j]]++;
			if(b[c[j]]>1){
				for(int k=j-1;k>=1;k--){
					b[c[k]]--;
					c[k]==0;
				}
			}
			for(;j<=n;j++){
				b[c[j]]++;
			}
		}
	}
	for(int z=1;z<=m;z++){
		cout<<b[z]<<"　";
	}
	return 0;
}
