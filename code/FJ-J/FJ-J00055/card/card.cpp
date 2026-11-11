#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(b,-1,sizeof(b));
	memset(a,-1,sizeof(a));
	int m,n;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			for(int k=i; k<=j-1; k++){
				if(a[k]==a[j]){
					for(int f=k+1; f<=j; f++){
						b[f]=0;
					}
				}
			}
		}
	}
	return 0;
}
