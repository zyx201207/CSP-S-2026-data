#include<bits/stdc++.h>
using namespace std;
int n,m,a[500003],b[300006];
bool d[300006];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		if(d[a[j]]){
			for(int i=1;i<=m;i++){
				d[i]=0;
			}
		}
			d[a[j]]=1;
		}
		for(int i=1;i<=m;i++){
				if(d[i]){
					b[i]++;
					d[i]=0;
				}
			}
	}
	for(int i=1;i<=m;i++){
				cout<<b[i]<<" ";
		}
	return 0;
}
