#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i = 0;i < n;i++)cin >> a[i];
	int b[m] = {};
	for(int i = 0;i < n;i++){
		int al[n-i];
		for(int j = 0;j < n-i;j++){
			al[j] = a[j+i];
			for(int k = 0;k < j;k++)if(al[k] == al[j]){
				for(int l = k;l < j;i++)al[l] = 0;
				break;
			}
		}
		for(int j = 0;j < n-i;j++){
			b[al[j]]++;
		}
	}
	for(int i = 1;i < m;i++)cout << b[i] << ' ';
	return 0;
}
