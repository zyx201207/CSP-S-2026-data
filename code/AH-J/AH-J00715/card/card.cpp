#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1111111],b[1111111],c[1111111],s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int k=i;k<j;k++) if(b[k]==b[j]){
				for(int o=k;o<j;o++) b[o]=0;
				break;
			}
		}
		for(int l=i;l<=n;l++) if(b[l]) c[b[l]]++;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
