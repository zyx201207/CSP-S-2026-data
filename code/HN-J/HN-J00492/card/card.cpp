#include <bits/stdc++.h>
using namespace std;
int a[5000009],c[3000009];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=1,b[3000009];
		for(int j=i;j<=n;j++){
			b[k]=a[j];
			for(int o=1;o<=k-1;o++){
				if(b[o]==b[k]){
					for(int h=o;h<=k;h++) a[h]=0;
					k=k-o;
					break;
				}
			}
			b[k]=a[j];
			k++;
		}
		for(int i=1;i<k;i++){
			c[b[i]]++;
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
    return 0;
}
