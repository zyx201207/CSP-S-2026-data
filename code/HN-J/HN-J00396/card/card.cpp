#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[7891];
long long p=1,ans[9871];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		long long c[7198];
		for(int j=i;j<=n;j++,p++){
			c[p]=a[j];
			for(int k=1;k<p;k++){
				if(c[k]==c[p]){
					for(int l=k+1;l<=p;l++)c[l]=0;
					p=k;
					break;
				}
			}
		}
		for(int j=1;j<=p-1;j++){
			ans[c[p]]++;
		}
		p=1;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
} 
