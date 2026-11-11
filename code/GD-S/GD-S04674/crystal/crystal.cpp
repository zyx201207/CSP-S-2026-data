#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e+7;
int n,m;
int a[MAXN];
int u=1;
int b[MAXN];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[1];
	}
	int q=0;
	int z;
	for(int i=1;i<=n;i++){
		if(b[i]<=m){
			q=max(q,b[i]);
			z=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(a[u]!=a[z]){
			a[u]++;
		}
		else{
			u++;
			if(a[u]!=a[z]){
				a[u]++;
			}
		}
	}
	int p=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[z]){
			p++;
		}
	}
	cout<<p;
	return 0;
}
