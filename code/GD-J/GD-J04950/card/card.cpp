#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[5005];
int b[5005];
int v[5005];
int v2[5005];
int v3[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int now=i-1;
		memset(v,0,sizeof(v));
		memset(v2,0,sizeof(v2));
		for(int j=i;j<=n;j++){
			if(v[a[j]]){
				for(int i=v2[a[j]]+1;i<=now;i++){
					v[b[i]]=0;
				}
				now=v2[a[j]];
			}else{
				v[a[j]]=1;
				b[++now]=a[j];
				v2[a[j]]=now;
			}
			
		}
		for(int j=i;j<=now;j++){
			v3[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v3[i]<<' ';
	}
	return 0;
} 
