#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000],c[10000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,q=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=0;
			for(int k=1;k<=q;k++){
				if(b[k]==a[j]){
					q=k;
					t=1;
					break;
				}
			}
			if(t==0){
				q++;
				b[q]=a[j];
			}
		}
		for(int j=1;j<=q;j++){
			c[b[j]]++;
			
		}
		q=0;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
