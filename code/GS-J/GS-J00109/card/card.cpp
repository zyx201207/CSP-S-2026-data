#include<bits/stdc++.h>
using namespace std;

int n,m,a[500100],b[300100];
int p[500100];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int k=1;
	while(k<=n){
		memset(p,0,sizeof(p));
		int t=0;
		for(int i=k;i<=n;i++){
			int f=0;
			for(int j=1;j<=t;j++){
				if(p[j]==a[i]){
					f=j;
					break;
				}
			}
			if(f){
				t=f-1;
			}
			t++;
			p[t]=a[i];
		}
		for(int i=1;i<=t;i++) b[p[i]]++;
		k++;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
