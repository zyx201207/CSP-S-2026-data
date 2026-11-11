#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,m,an;
long long a[N],ax[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m >> a[1];
	for(int i = 2;i <= n;i++){
		cin >> a[i];
		if(m==1) ax[i] = a[i];
		if(m==2) ax[i] = a[i]&a[i-1];
		an = max(ax[i],an);
	}cout << an;
	return 0;
}
