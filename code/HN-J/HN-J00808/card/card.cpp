#include<bits/stdc++.h>
using namespace std;
int n,m,c[500005],d[300005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>c[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			a[j] = 0;
		}
		for(int j = i;j <= n;j++){
			a[j] = c[j];
		}
		for(int j = i;j <= n;j++){
			for(int x = j+1;x <= n;x++){
				if(a[j] == a[x]){
					for(int e = j;e < x;e++){
						a[e] = 0;
					}
				}
			}
		}
		for(int j = 1;j <= n;j++){
			if(a[j] != 0){
				d[a[j]]++;
				a[j] == 0;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
