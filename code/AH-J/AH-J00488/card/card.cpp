#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005],b[300005]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int c[500005];
		bool d[500005];
		for(int j=i;j<n;j++){
			int e=a[i];
			if(d[e]==1){
				int pd=0;
				for(int k=0;k<=j;k++){
					if(c[k]==a[j]){
						pd=1;
					}
					if(pd==1){
						c[k]=0;
					}
				}
			}
			c[j]=a[j];
			d[e]=1;
		}
		for(int j=0;j<n;j++){
			if(c[j]!=0){
				int e=c[j];
				b[e]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
}
