#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005];
int main(){
	freopen("card.in","t",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int b[500005],cnt=0;
		for(int j=i;j<=n;j++){
			int k=0;
			while(k<cnt){
				if(b[k]==a[j]){
					cnt=k;
					break;
				}
				k++;
			}
			b[cnt++]=a[j];
		}
		for(int j=0;j<cnt;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}

