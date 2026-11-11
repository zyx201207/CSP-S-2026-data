#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[500005],b[300005],c[300005],p[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++){
			p[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			for(int k=n;k>=j+1;k--){
				if(p[j]==p[k]&&p[j]!=0){
					for(int l=k;l>=j+1;l--){
						p[l]=0;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			c[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
