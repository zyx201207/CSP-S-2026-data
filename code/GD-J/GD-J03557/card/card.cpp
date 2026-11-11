#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int t=1;t<=n;t++){
		int q[300010]={},r=0;
		for(int i=t;i<=n;i++){
			for(int j=0;j<r;j++){
				if(a[i]==q[j]){
					r=j;	
					break;
				}
			}
			q[r++]=a[i];
		}
		for(int i=0;i<r;i++)ans[q[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
