#include<bits/stdc++.h>
using namespace std;
const int M=10000005;
long long n,m,a[M],l=1,b[M],c[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		
		for(int j=i;j<=n;j++){
			for(int k=1;k<j;k++){
				if(a[k]==a[j]){
					l=k;
				}
			}
			c[l]=a[j];
			l++;
		}
		for(int x=1;x<l;x++){
			b[c[x]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << b[i] << " ";
	}
	return 0;
}
