#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m,a[100010],k=1,t[100010];
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k<=n){
		int o=1,z[100010],v[100001],w[100001];
		for(int i=k;i<=n;i++){
			if(v[a[i]]==0){
				z[o]=a[i];
			}
			else {
				for(int j=o-1;j>=w[a[i]];j--){
					z[j]=0;
					v[z[i]]=0;
					w[z[i]]=0;
					o=j;
				}
			}
			z[o]=a[i];
			v[a[i]]=1;
			w[a[i]]=o;
		}
		for(int i=1;i<=m;i++){
			if(z[i]!=0) t[a[i]]++;
		}
		k++;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i];
	}
	return 0;
}
