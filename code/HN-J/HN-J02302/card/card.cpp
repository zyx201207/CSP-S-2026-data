#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000000],b[1000000],c[1000000],d[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int x=i;x<j;x++){
				if(a[x]==a[j]){
					for(int q=c[a[x]];q<j;q++){
						b[a[q]]=0;
					}
					break;
				}
			}
			b[a[j]]++;
			c[a[j]]=j;
		}
		for(int j=i;j<n;j++){
			if(b[a[j]]!=0){
				d[a[j]]++;
				b[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
