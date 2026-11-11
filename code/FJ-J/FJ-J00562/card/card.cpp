#include<bits/stdc++.h>
using namespace std;
long long a[500001],c[300001],d[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long b[300001]={0},e[300001]={0};
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]++;
				d[a[j]]=j;
			}
			else if(b[a[j]]>=1){
				b[a[j]]++;
				for(int k=d[a[j]];k<j;k++){
					if(e[k]==0){
						b[a[k]]--;
						e[k]=1;
					}
				}
				d[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(e[j]==0){
				c[a[j]]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<c[j]<<" ";
	}
	return 0;
}
