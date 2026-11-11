#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int n,m;
int xia=1,cnt[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<xia;k++){
				if(a[j]==b[k]){
					for(int t=1;t<xia;t++){
						b[t]=0;
					}
					xia=1;
					break;
				}
			}
			b[xia]=a[j];
			xia++;
		}
		for(int j=1;j<=xia;j++){
			int t=b[j];
			cnt[t]++;
		}
		for(int t=1;t<xia;t++){
			b[t]=0;
		}
		xia=1;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
