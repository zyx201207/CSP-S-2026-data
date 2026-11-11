#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005]={0},cnt[300005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int q=j;q<=j+j;q++){
				if(a[j]==b[q]){
					for(int s=q;s<=q+q;s++){
						b[s]=0;
					}
					break;
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int q=1;q<=m;q++){
				if(b[j]==q){
					cnt[q]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
