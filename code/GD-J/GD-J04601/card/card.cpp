#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],k,s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i;j<=n;j++){
			for(int p=k;p>=1;p--){
				if(b[p]==a[j]){
					k=p-1;
					break;
				} 
			}
			b[++k]=a[j];
		}
		for(int j=1;j<=k;j++) s[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<s[i];
}
