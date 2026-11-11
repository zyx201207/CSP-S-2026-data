#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long xing[5005];
long long yuan[5005];
long long weizhi[5005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>yuan[i];
	}
	for(int i=1;i<=n;i++){
		int c=0;
		for(int j=1;j<=m;j++){
			weizhi[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(weizhi[yuan[j]]==0){
				c++;
				xing[c]=yuan[j];
				weizhi[yuan[j]]=c;
			}else{
				for(int z=weizhi[yuan[j]]+1;z<=c;z++){
					weizhi[xing[z]]=0;
				}
				c=weizhi[yuan[j]];
			}
		}
		for(int j=1;j<=c;j++){
			a[xing[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
