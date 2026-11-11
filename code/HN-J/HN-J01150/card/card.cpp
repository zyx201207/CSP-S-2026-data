#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[300005];
int c[300005];
int d[500005];
int e[500005];
int kk[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=n;i>=1;i--){
		if(b[a[i]]==0){
			d[a[i]]=i; 
			b[a[i]]=i;
		}else{
			c[i+1]--;
			c[d[a[i]]]++;
			d[a[i]]=i;
		} 
	}
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+c[i];
		e[a[i]]+=c[i];
	} 
	for(int i=1;i<=m;i++){
		kk[i]=e[i]+b[a[i]];
	}
	kk[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout << kk[i] << " ";
	} 
	return 0;
}
