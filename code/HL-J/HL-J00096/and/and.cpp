#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,maxn=-10000;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m >> a[1];
    for(int i=2;i<=n;i++){
    	cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int l=a[i]&a[j];
			maxn=max(maxn,l);
		}
	}
	cout << maxn;
    return 0;
}
//4 2
//3 15 12 12

