#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],p[500005],k[500005];
vector<ll>v[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}ll i=1;
	while(i<=n){
		for(int j=1;j<=m;j++)
		v[j].clear();
		memset(k,0,sizeof(k));
		for(int j=1+i-1;j<=n;j++){
			k[a[j]]++;
			if(k[a[j]]>1){
				k[a[j]]=1;
				for(auto ed:v[a[j]]){ 
				a[ed]=0;
					if(a[ed+1]!=a[j])
					k[ed+1]--;
				}
			}v[a[j]].push_back(j);
		}for(int j=1;j<=m;j++){
			if(k[j])p[j]++;
		}
		i++;
	}for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}fclose(stdin);
	fclose(stdout);
	return 0;
} 
