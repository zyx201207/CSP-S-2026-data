#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],h[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			if(a[i]==b[j]){
				for(int q=j;q>=1;q--){
					b[q]=0;
					h[q]-=1;
				}
			}
		}
		b[i]=a[i];
		h[a[i]]++;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i]==b[j]){
				for(int q=j;q>=1;q--){
					b[q]=0;
					h[q]-=1;
				}
			}
		}
		b[i]=a[i];
		h[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
	return 0;
}