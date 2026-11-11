#include<bits/stdc++.h> 
using namespace std;
long long n,m;
long long card[500011];
long long now[500011];
long long ans[300011];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int z=1;z<=n;z++){
				if(card[j]==now[z]){
					for(int k=z;z<=n;z++){
						now[z]=0;
					}
				}
			}
			now[j]=card[j];
		}
		for(int j=1;j<=n;j++){
			ans[now[j]]++;
		}
		for(int j=1;j<=n;j++){
			now[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
