#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int tong[300010];
int que[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int b[n+1];
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		int hed=i;
		int tel=i-1;
		for(int j=i;j<=n;j++){
			for(int k=hed;k<=tel;k++){
				if(que[k]==b[j]){
					tel=k-1;
					break;
				}
			}
			tel++;
			que[tel]=b[j];
		}
		for(int j=hed;j<=tel;j++){
			tong[que[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << tong[i] << ' ';
	}
	return 0;
}
