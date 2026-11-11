#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans[300020],c[500020];
long long judge[300020]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		long long judge[m]={0};
		for(int j=i;j<=n;j++){
			if(judge[c[j]]==0){
				judge[c[j]]=j;
			}
			else {
				for(int k=1;k<=m;k++){
					if(judge[k]>judge[c[j]]&&k!=c[j]) judge[k]=0;
				}
				judge[c[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(judge[j]!=0) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
