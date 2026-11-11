#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500005];
	int b[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m--){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(b[j]==a[i]){
					a[i]=b[j];
					b[j]=0;
				}
			}
			b[i]+=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
