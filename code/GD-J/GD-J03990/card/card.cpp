#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],t[300005],k[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int z=0;
		if(a[i]==a[n]){
			ans[a[i]]++;
		}else{
			for(int j=i;j<=n;j++){
				if(t[a[j]]==0){
					z++;
					t[a[j]]=z;
					k[z]=a[j];
				}else{
					for(int d=1;d<=m;d++)if(t[a[j]]<t[d])t[d]=0; 
					z=t[a[j]];
				}
			}
			for(int j=1;j<=z;j++)ans[k[j]]++;
			fill(t+1,t+1+m,0);
			fill(k+1,k+1+n,0);
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" "; 
	return 0;
}
