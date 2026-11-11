#include<bits/stdc++.h>
using namespace std;
long long n,m;
int k[500005];
int zhan[500005];
int tong[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
	}
	for(int i=1;i<=n;i++){
		int r=0;
		for(int j=i;j<=n;j++){
			int f=0;
			for(int t=1;t<=r;t++){
				if(zhan[t]==k[j]){
					f=t;
					break;
				}
			}
			if(f==0){
				r++;
				zhan[r]=k[j];
			}else{
				r=f;
			}
		}
		for(int t=1;t<=r;t++){
			tong[zhan[t]]++;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<' ';
	}
	return 0;
}
