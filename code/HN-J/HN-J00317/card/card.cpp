#include<bits/stdc++.h>
using namespace std;
int n,m,a[555555],d[555555];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		d[a[i]]++;
	}
	for(int i=1;i<=n;i++) cout <<d[i]<<" ";
	return 0;
} 
