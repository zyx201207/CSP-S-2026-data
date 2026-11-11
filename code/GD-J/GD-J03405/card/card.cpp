#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		for(int b=j+1;b<n-1;b++){
			if(a[j]==a[b+1]){
				for(int c=j;c<=b+1;c++){
					a[c]=0;
				}
			}
		}
	}
	cout << a; 

	
	
	return 0;
}
