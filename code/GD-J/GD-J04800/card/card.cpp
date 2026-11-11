#include<bits/stdc++.h>
using namespace std;
int a[1000005],t[1000005],b[1000005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int g = 0;g < n;g++){
		for(int i = g;i < n;i++){
		b[i] = a[i];
	}
		for(int i = g;i < n-1;i++){
			for(int j = i+1;j <n;j++){
				if(b[i] == b[j] && b[i] != 0 && b[j] != 0){
					for(int k = i;k < j;k++){
						b[k] = 0;
						i = j;
					}
				}
			}
		}
	for(int i = g;i< n;i++){
		t[b[i]]++;
	}
}
	for(int i = 1;i<=m;i++){
		cout << t[i] << " ";
	}
	return 0;
}
