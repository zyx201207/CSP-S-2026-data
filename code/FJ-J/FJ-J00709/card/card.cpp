#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],v[500005],vi[500005],vj[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			v[a[j]]++;
			if(v[a[j]]>1)for(int k=j;k>=1;k--){
				if(a[k]==a[j])break;
				vj[a[k]]++;
			}
		}
		for(int j=1;j<=n;j++)if(vj[j]!=0)vi[j]++; 
		for(int j=1;j<=n;j++)vj[j]=0,v[j]=0; 
	}
	for(int i=1;i<=n;i++)if(vi[i]!=0)cout<<vi[i]<<" ";
	return 0;
}
