#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans[300005],f[300005];
bool txa=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])txa=0;
	}
	if(txa){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}
		for(ll i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}	
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(f[x]){
				for(int k=1;k<=m;k++){
					if(f[k]>f[x]){
						f[k]=0;
					}
				}
			}
			f[x]=j;
		}
		for(int j=1;j<=m;j++){
			if(f[j]){
			ans[j]++;
			f[j]=0;
			}
		} 
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
} 
