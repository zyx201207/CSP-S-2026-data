#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int x=j+1;x<=n;x++){
				if(a[j]==a[x]){
					for(int k=j;k<x;k++){
						b[a[k]]--;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << b[m] << ' ';
	}
	return 0;
}
