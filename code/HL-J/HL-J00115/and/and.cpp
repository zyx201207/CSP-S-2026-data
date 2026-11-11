#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long num=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>> n >> m;
	for(int i=1; i<=n; i++){
		cin>> a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			num=max(num,(a[i]&a[j]));
		} 
	}
	cout<< num;
	return 0;
}
