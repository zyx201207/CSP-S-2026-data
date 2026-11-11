#include<bits/stdc++.h>
using namespace std;
int p[300005],a[300005],l[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,k=0;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>p[i];
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(a[p[j]]==0) a[p[j]]=++k;
			else{
				k=a[p[j]];
				for(int x=1;x<=m;x++){
					if(a[p[x]]>k) a[p[x]]=0;
				}
			}
		}
		for(j=1;j<=m;j++){
			if(a[j]!=0) l[j]++;
			a[j]=0;	
		} 
	}
	for(i=1;i<=m;i++) cout<<l[i]<<" "; 
	return 0;
} 
