#include<bits/stdc++.h>
using namespace std;
int m,n,cf=0;
int c[600000],ans[600000],sum[600000]={0};
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin >> n >> m;
for(int i=1;i<=n;i++){
	cin>>c[i];
}
if(n<=5 and m==1){
	for(int i=1;i<=n;i++)
	sum[c[i]]++;
	for(int i=1;i<=n;i++){
		if(sum[i]==0) continue;
	cout<<sum[i]<<" ";}
	return 0;
}

for(int i=1;i<=m;i++){
	for(int j=i;j<=m;j++){
		cf++;
		ans[cf]=c[j];
		for(int k=1;k<=i;k++){
			if(c[k]==c[j]){
			cf=k;
			continue;
			}
		}
		}
		for(int j=1;j<=cf;j++){
			sum[c[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<sum[i]<<" ";
	}
}

