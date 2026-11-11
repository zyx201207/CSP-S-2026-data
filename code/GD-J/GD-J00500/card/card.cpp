#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500010],ton[300010];
ll n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]==a[j-1]){
				a[j-1]=0;
			}
		}
		for(int j=i;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(a[j]==k){
					ton[k]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ton[i]<<" ";
	}
	return 0;
}

