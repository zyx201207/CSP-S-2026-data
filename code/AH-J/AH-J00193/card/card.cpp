#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1000010],b[1000010],cnt[1000010]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=1;
	while(p<=n){
		int i;
		for(i=p;i<=n;i++){
			b[i]=a[i];
			
		}
		for(i=p;i<=n;i++){
			for(int j=p;j<=i;j++){
				if(b[j]==b[i]){
					a[i]=b[i];
					break;
				}
			}
			cnt[b[i]]++;
		}
		p++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
