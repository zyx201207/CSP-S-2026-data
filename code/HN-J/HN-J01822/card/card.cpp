#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],x[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[N];
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(b[k]==a[j]){
					for(int q=k;q<j;q++){
						b[q]=0;
					}
				}
			}
			b[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			if(b[j]<=m){
				x[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<' ';
	}
	return 0;
}

