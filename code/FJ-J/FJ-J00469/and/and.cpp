#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[2*100000+5];
long long ans;
bool cmp(int z, int x){
	int l=0, r=0;
	bool w = z<x;
	while(z>0){
		if(z%2==1)
			l++;
		z=z>>1;
	}
	while(x>0){
		if(x%2==1)
			r++;
		x=x>>1;
	}
	if(l < r)	return 1;
	if(l == r)	return w;
	return 0;
}
void msort(){
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(cmp(a[i],a[j])){
				int u = a[i];
				a[i] = a[j];
				a[j] = u;
			}
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		//b[y]=1;
	}
	msort();
	ans = (1<<30) - 1;/*
	for(int i = 0 ; i < n; i++){
		cout << a[i] <<"\n";
	}
	*/
	for(int i = 0; i < m; i++){
		ans=ans&a[i];
	}
	cout << ans;
	
	return 0;
} 
