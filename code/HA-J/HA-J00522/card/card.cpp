#include <bits/stdc++.h>
using namespace std;
bool c[300005];
int sum[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.ont","w",stdout);
	int a[30005],top;
	int m,n,k,l[50005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			k=l[i];
			if(c[k]==0){
				a[++top]=k;
				c[k]=1;
			}
			else{
				while(1){
					if(a[top]==k){
						top--;
						break;
					}
					else{
						c[a[top]]=0;
						top--;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(c[i]){
				sum[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}