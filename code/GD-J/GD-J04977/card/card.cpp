#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],b[500100],c[300100],d[300100];
bool cnt[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(d[a[i]]!=0){
			b[i]=d[a[i]];
		}d[a[i]]=i;
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt[j]=1;
		}
		for(int j=i;j<=n;j++){
			if(b[j]>=i&&cnt[b[j]]==1){
				for(int z=b[j];z<j;z++){
					cnt[z]=0;
				}
			}
		}for(int j=i;j<=n;j++){
			if(cnt[j]==1){
				c[a[j]]++;
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
