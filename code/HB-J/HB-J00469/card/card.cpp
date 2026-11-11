#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],v[500005],sum[500005];
int q[500005],p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		p=1;
		for(int j=1;j<=m;j++){
			v[j]=0;
		}
		for(int j=i;i<=n;j++){
			if(v[a[j]]==0){
				q[p]=a[j];
				v[a[j]]=1;
				p++;
				
			}
			else{
				for(;1;){
					p--;
					if(q[p]==a[j]){
						break;
					}
					q[p]=0;
					v[q[p]]=0;
				}
				p++;
			}
		}
		for(int j=1;j<=p-1;j++){
			sum[q[j]]=sum[q[j]]+1;
		}
		
		
	}
	for(int i=1;i<=m;i++){
		if(i==m){
			cout<<sum[i];
		}
		else{
			cout<<sum[i]<<" ";
		}
	}
	return 0;
}
