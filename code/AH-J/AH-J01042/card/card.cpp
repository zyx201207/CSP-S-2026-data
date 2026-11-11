#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int cn=i;
		for(int j=i;j<n;j++){
			int jiwei=0;
			for(int k=n-1;k>=j;k--){
				if(a[k]==a[j]){
					jiwei=k;
					break;
				}
			}
			b[cn++]=a[j];
			j=jiwei;
		}
		for(int j=i;j<cn;j++){
			cnt[b[j]]++;
		}
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";        
	}
	return 0;
}
