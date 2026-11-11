#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005]={0},c[300005],a1[300005],e=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e++;
			
			if(c[a[j]]==0){
				c[a[j]]=1;
				a1[e]=a[j];
				
		    }else{
				int d=lower_bound(a1+1,a1+1+e,a[j])-a1;
				for(int k=d+1;k<=e;k++){
					c[a1[k]]=0;
					a1[k]=0;
			    }
				e=d;
			}
			
		}
		for(int j=1;j<=e;j++){
			cout<<a1[j]<<" ";
		}
		for(int j=1;j<=m;j++){
			
			b[m]=b[m]+c[m];
			
		}
	}
	for(int i=1;i<=m;i++){
			cout<<b[m]<<" ";
   }
    return 0;
}

