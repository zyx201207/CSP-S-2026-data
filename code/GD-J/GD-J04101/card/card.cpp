#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int v[500005];
int cd[500005];
int ans[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		memset(cd,0,sizeof(cd));
		int k=i-1;
		int cnt=n+1;
		for(int j=k+1;j<=n;j++){
			if(v[a[j]]==0){
				cd[--cnt]=a[j];
				v[a[j]]=cnt;
			}else{
				for(int z=v[a[j]];z<=n;z++){
					if(cd[z]!=0){
						cd[z]=0;
					}
				}
				cnt=n;
				
				cd[n]=a[j];
			}
		}
			for(int p=1;p<=n;p++){
			 ans[cd[p]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
