#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],pos,b[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int z=1;z<=n;z++){
		memset(b,0,sizeof(b));
		for(int i=z;i<=n;i++){
			bool f=1;
			for(int j=0;j<pos;j++){
				if(b[j]==a[i]){
					f=0;
					for(int k=j+1;k<pos;k++){
						b[k]=0;
					}
					pos=j+1;
				}
			}
			if(f) b[pos++]=a[i];
		}
		for(int j=1;j<=m;j++){
			for(int i=0;i<pos;i++){
				if(b[i]==j) ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
