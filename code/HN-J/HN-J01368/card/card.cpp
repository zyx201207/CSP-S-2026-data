#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int d=1;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(b[j]==a[i]){
					d=j;
					b[j+1]=0;
				}
				if(b[j-1]==0&&j!=1) b[j]=0;
			}
			b[d++]=a[i];
		}
		for(int i=1;i<=n;i++){
			c[b[i]]++;
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}	
	return 0;
}
