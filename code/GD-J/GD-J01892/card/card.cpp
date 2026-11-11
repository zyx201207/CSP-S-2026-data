#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,a[500005],b[500005],c[300005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n>=5000){
		if(m<=2){
			for(int i=1;i<=n;i++)
				scanf("%d",&a[i]);
			for(int i=1;i<=n;i++)
				if(a[i]!=a[n]) k++;
			if(m==1) cout<<n<<"\n";
			else{
				if(a[n]==1) cout<<n<<" "<<k;
				else cout<<k<<" "<<n;
			}
		}
		else{
			for(int i=1;i<=n;i++)
				scanf("%d",&a[i]);
			for(int i=1;i<=n;i++)
				d[a[i]]=1;
			for(int i=1;i<=m;i++)
				cout<<d[i]<<" ";
		}
	}
	else{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			k=i;
			for(int j=i;j<=n;j++)
				b[j]=0;
			for(int j=1;j<=m;j++)
				c[j]=0;
			for(int j=i;k<=n;k++){
				if(c[a[k]]){
					for(int l=c[a[k]]+1;l<=j;l++)
						c[b[l]]=0,b[l]=0;
					j=c[a[k]],b[j]=a[k],s=j;
				}
				else c[a[k]]=j,b[j]=a[k],s=j;
				j++;
			}
			for(int j=i;j<=s;j++)
				d[b[j]]++;
			
		}
		for(int i=1;i<=m;i++)
			printf("%d ",d[i]);
	}
	
	return 0;
} 
