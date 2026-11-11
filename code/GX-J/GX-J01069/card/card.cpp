#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int a[200100],zd=0,jg[200100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ts=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zd=max(zd,a[i]);
	}
	while(ts--){
		int b[ts+10];
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
		for(int i=n-ts;i<=n;i++){
			b[i]=a[i];
			for(int j=n-ts;j<i;j++){
				if(b[j]==a[i]){
					for(int k=j;k<i;k++){
						b[k]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<b[i]<<" ";
			jg[b[i]]++;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<jg[i]<<" ";
	}
	return 0;
}
