#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],c[300010] = {};
int h,g;
void find(int k){
	int cnt = k;
	b[k] = a[k];
	for(int i = k+1;i <= h;i++){
		b[i] = a[i];
		cnt++;
		for(int j = k;j <= cnt;j++){
			if(b[j] == a[i]){
				for(int l = b[j];l <= cnt;l++){
					b[l] = 0;
				}
			}
		}
	}
	for(int i = 1;i <= h;i++){
		c[b[i]]++;
	} 
}
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	h = n;
	g = m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 0;i <= n;i++){
		find(i);
	}
	for(int i = 1;i <= m;i++){
		cout << c[i] << " ";
	}
	return 0;
} 
