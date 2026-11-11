#include<bits/stdc++.h>
using namespace std;

const int maxx=3e5+5;
int n,m;
long long a[maxx];
long long b[maxx];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int u=1;u<=n;u++){
		int k=0;
		for(int i=u;i<=n;i++){
			b[a[i]]++;
			for(int j=u;j<=k;j++){
				if(a[i]==a[j]){
					for(int l=1;l<=j+1;l++){
						b[a[l]]--;
//						cout<<a[l]<<" ";
					}
				}
			}
			k++;
//			for(int i=1;i<=m;i++){
//				cout<<b[i]<<" ";
//			}
//			cout<<"\n";
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

