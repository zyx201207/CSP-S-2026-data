#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[n+2],p[m+2]={0},num[n+2];
		for(int j=i;j<=n;j++){
			c[j]=a[j];
			p[a[j]]++;
			if(p[a[j]]>1){
				for(int l=num[a[j]];l<j;l++){
					c[l]=0;
					p[a[l]]=0;
				}
				p[a[j]]=1;
			}
			num[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(p[j]==1) ans[j]++;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
    return 0;
}
