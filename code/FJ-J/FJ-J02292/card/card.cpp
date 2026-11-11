#include <bits/stdc++.h>
using namespace std;

int n,m, i, j, l, w;
int a[510000], sum[310000], lastpos[310000] = {0};
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(i = 0;i<n;++i){
		cin>>l;
		a[i] = l;
		lastpos[l] = i;
	}
	
	for(i = 0;i<n;++i){
		l = i;
		while(l<n){
			w = a[l];
			++sum[w];
			if(lastpos[w]>=i){
				l = lastpos[w];
			}
			++l;
		}
	}
	for(i = 1;i<=m;++i){
		cout<<sum[i]<<" ";
	}
	
	return 0;
}
