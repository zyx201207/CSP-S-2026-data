#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l=0,k=0,y;
	cin >> n >> m;
	int a[n],b[m],c[n];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		c[i] = 0;
	}
	for(int i = 1;i <= m;i++){
		b[i] = 0;
	}
	for(int t = 1;t <= n;t++){
		l = 0;
		for(int i = t;i <= n;i++){
			k = 0;
			for(int j = 1;j <= l;j++){
				if(k == 1){
					c[j] = 0;
				}else if(c[j] == a[i]){
					c[j] = 0;
					k = 1;
					y = j;
				}
				
			}
			l = y;
			l++;
			c[l] = a[i];
		}
		for(int i = 1;i <= l;i++){
			b[c[i]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << b[i] << " ";
	}
	return 0;
}

