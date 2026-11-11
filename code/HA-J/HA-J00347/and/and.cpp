#include<bits/stdc++.h>
using namespace std;
int a[35][20005], b[35][20005], n, m ,x ;
int z=20000,y,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> x;
		int s=0;
		while(x>=0){
			s++;
			a[i][s]=x%2;
			if(a[i][s]==1)  a[34][s]++;
			x/=2;
		}
		a[i][20004]=x;
	}
	for (int i = z; i> 0 ; i--){
		if (a[34][i] >= m ){
			z=i;
			y = m;
		}
	}
	for (int i = 1; i<= m ; i++){
		for (int j = 1; j<= z ; j++){
			b[i][j]==a[i][j];
	    }
	}
	while(y = m){	
		for (int i = z-1; i> 0 ; i--){
			if (b[34][i] >= m ){
				z=i;
				y = m;
			}
		}
		for (int i = 1; i<= m ; i++){
			for (int j = 1; j<= z ; j++){
				b[i][j]==a[i][j];
	   	    }
		}
	}
	for(int i=z; i>=1;i++){
		int v=0;
		v++;
		if(a[34][i]>0){
			s += 2^v;
		}
	}
	cout << s;
	return 0;
}
