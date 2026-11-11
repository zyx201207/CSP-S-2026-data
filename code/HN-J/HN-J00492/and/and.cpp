#include <bits/stdc++.h>
using namespace std;
int a[200009],b[200009],c[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum;
	bool z,y;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=1,l=1;
		while(1){
			if(k>=a[i]){
				b[i]=k-a[i];
				c[i]=l;
				break;
			}
			k=k*2;
			l++;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			z=c[j]<c[j+1];
			y=(c[j]==c[j+1])&&(b[j]>b[j+1]);
			if(z||y){
				swap(b[j],b[j+1]);
				swap(a[j],a[j+1]);
				swap(c[j],c[j+1]);
			}
		}
	}
	sum=a[1];
	for(int i=1;i<=m;i++){
		sum=(sum&a[i]);
	}
	cout<<sum;
    return 0;
}

