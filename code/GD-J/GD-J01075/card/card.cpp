#include <bits/stdc++.h>
using namespace std;
int a[600000],b[600000][2];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,b,k=0,c=0;
	cin >> m >> n;
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		b[600000][1]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=c;j>=n;j++){
			for(int p=1;p<=j;p++){
			if(a[j]==a[p]){
				k=p;
			}
		}
		}
		for(int q=1;q<=n-k;q++){
			a[n-k+q]=b[n-k+q][2];
		}
		k=0;
		c++;
	}
	for(int i=1;i<=n;i++){
		cout << b[i];
	}
	return 0;
}
