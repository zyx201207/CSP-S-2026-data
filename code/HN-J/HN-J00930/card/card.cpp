#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a[n],c[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int d=-1;
	for(int i=0;i<n;i++){
		d++;
		int b[n];
		for(int j=d;j<n;j++){
			b[j]=a[j];
			for(int t=0;t<n;t++){
				cout<<b[t]<<" ";
			}
			cout<<endl;
		}
		for(int h=0;h<n;h++){
			if(b[h]>0){
				c[b[h]]++;
				break;
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
