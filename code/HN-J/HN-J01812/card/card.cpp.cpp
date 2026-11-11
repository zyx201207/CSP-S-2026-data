#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	long long n,m,x;
	int a[10001],b[10001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int y=0;
	for(int i=1;i<=n;i++){
		y++;
		for(int r=y;r<=n;r++){
			b[r]=a[r];
			for(int z=1;z<=y;z++){
				if(b[z]==b[r]){
					for(int x=z;x<r;x++){
						b[x]=0;
					}
				}
			}
		}
		for(int c=1;c<=n;c++){
			if(b[c]>0) b[b[c]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}

	return 0;
}
