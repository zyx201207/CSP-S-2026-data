#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		ans[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	int x=n;
	for(int i=1;i<=n;i++){
		int b[500005];
		
		for(int k=i;k<=n;k++){
			
			if(b[a[k]]>0){
			for(int j=b[a[k]]+1;j<=k;j++){
				c[j]=0;
			}
			
		}
		b[c[k]]=k;
		}
		for(int j=1;j<=m;j++){
			if(b[j]>=1){
				ans[j]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
