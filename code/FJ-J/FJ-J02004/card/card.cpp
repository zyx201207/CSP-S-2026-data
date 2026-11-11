#include<bits/stdc++.h>
using namespace std;
int a[200005],ans[200005],c[200005],f[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mnc=1;
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(f[a[i]]==0){
				c[mnc]=a[i];
				f[a[i]]++;
				mnc++;
			}else{
				
				for(int k=1;k<=m;k++)f[k]=0;
				mnc=1;
				c[mnc]=a[i];
				mnc++;
				f[a[i]]++;
			}
		}
		for(int k=1;k<=mnc;k++){
			ans[c[k]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

