#include<iostream>
using namespace std;
long long n,m;
long long a[500010];
long long b[500010],w;
long long c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	for(int i = 1; i <= n; i++){
		w = 1;
		for(int j = i; j <= n; j++){
			bool bl = 0;
			for(int k = 1; k < w; k++){
				if(b[k] == a[j] || bl){
					b[k] = 0;
					bl = 1;
					w--;
				}
			} 
			b[w] = a[j];
			w++;
		}
		for(int j = 1; j < w; j++){
			c[b[j]]++; 
			b[j] = 0;
		}
	}
	for(int i = 1; i <= m; i++){
		cout<<c[i]<<" ";
	} 
	return 0;
}
