#include <bits/stdc++.h>

using namespace std;

int cards[1000010];
int desk[1000010];
int h[1000010];
int n,m;

int find(int k,int n){
	for (int i=1;i<=n;i++){
		if (desk[i]==k){
			return i;
		}
	}
	return -1;
}

int main(){
	freopen("card.in","r",stdout);
	freopen("card.out","w",stdin);
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> cards[i];
	}
	int k=1;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			int f=find(cards[j],k);
			if (f!=-1){
				k=f-1;
			}
			k++;
			desk[k]=cards[j];
		}
		for (int j=1;j<=k;j++){
			//cout << desk[j] << " " << j << endl;
			h[desk[j]]++;
		}
		k=1;
	}
	for (int i=1;i<=m;i++){
		cout << h[i] << " ";
	}
}
