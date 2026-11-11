#include <iostream>
using namespace std;
int n,m,a[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int cmp[m+5]={0};
		for(int j=i;j<=n;j++){
			if(cmp[a[j]]){
				for(int k=1;k<=m;k++){
					if(cmp[k]<j&&cmp[k]>cmp[a[j]])cmp[k]=0;
				}
				cmp[a[j]]=j;
			}
			else cmp[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(cmp[j])cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
