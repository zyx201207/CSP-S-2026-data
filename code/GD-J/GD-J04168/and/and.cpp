#include <bits/stdc++.h>
using namespace std;
int n,m,a[200100],w,b[40],cnt,kk;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=30; i>=0; i--){
		int sum=0;
		for(int j=1; j<=n; j++){
			if((a[j]|(1<<i))==a[j]){
				sum++;
			}
		}
		if(sum>=m){
			w=i;
			break;
		}
	}
	b[++cnt]=w;
	kk=(1<<w);
	for(int i=w-1; i>=0; i--){
		int sum=0;
		for(int j=1; j<=n; j++){
			bool wk=0;
			for(int k=1; k<=cnt; k++){
				if((a[j]|(1<<b[k]))!=a[j]){
					wk=1;
					break;
				}
			}
			if(wk==0&&(a[j]|(1<<i))==a[j]){
				sum++;
			}
		}
		if(sum>=m){
			kk+=(1<<i);
			b[++cnt]=i;
		}
	}
	cout<<kk;
	return 0;
}
