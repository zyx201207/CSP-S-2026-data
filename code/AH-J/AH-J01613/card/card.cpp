#include<bits/stdc++.h>
using namespace std;
int a[10005],ans[10005],k[10005],b[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(k,0,sizeof(k));
		memset(b,0,sizeof(b));
		int t=0;
		for(int j=i;j<=n;j++){
			if(k[a[j]]==0){
				t++; 
				b[t]=a[j];
				k[a[j]]=t;
			}
			else{
				int c=k[a[j]];
				for(int ii=k[a[j]];ii<=t;ii++){
					k[b[ii]]=0;
					b[ii]=0;
				}
				t=c;
				b[t]=a[j];
				k[a[j]]=t;
			}
		}
		for(int j=1;j<=t;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
