#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500001],b[500001];
ll v[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			v[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(j==0){
				continue;
			}
			v[j]=a[j];
			for(int k=i-1;k<j;k++){
				if(v[k]==v[j]){
					for(int l=k;l<j;l++){
						v[l]=0;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			b[v[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			continue;
		}
		cout<<b[i]<<" ";
	}
	return 0;
}
