#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	int a[500001],b[500001],c[500001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
	}
	int w;
	for(int i=2;i<=n;i++){
		w=0;
		for(int j=i;j<=n;j++){
			w++;
			c[w]=a[j];
		}
		for(int j=1;j<i;j++){
			int ww=50000001;
			for(int q=1;q<=n;q++){
				if(q>=ww){
					c[q]=0;
				}
				if(c[q]==a[j]){
					w-=(n-q+1);
					ww=q;
					c[ww]=a[j];
					w++;
				}
				
			}
		}
		for(int j=1;j<=n;i++){
			b[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0; 
} 
