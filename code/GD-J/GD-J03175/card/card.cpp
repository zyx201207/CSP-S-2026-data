#include<bits/stdc++.h>
using namespace std;

int a[50005],b[30005],card[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for (int i = 1;i<=n;i++){
		for (int j = i;j<=n;j++){
			int p = 0;
			for (int v = 0;v<j;v++){
				card[j] = a[j];
					if(card[v]==card[j]){
						p=1;
					}
				}
			if(p) b[a[j]]+=1;
	}
	}

	for (int i = 1;i<=m;i++){
		//cout << card[i] << endl;
		cout << b[i] << " ";
	}
	return 0;
} 
