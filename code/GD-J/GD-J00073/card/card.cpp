#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],c[500005],d[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int t=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(t--){
		memset(c,-1,4);
		int h=0;
		for(int i=1;i<=n;i++){
			h++;
			for(int j=1;j<i;j++){
				if(a[i]==c[j]){
					h=j;
					for(int k=j;k<i;k++){
						c[k]=0;
					}
					break;
				}
			}
			c[h]=a[i];
		}
		for(int i=1;i<=h;i++){
			d[c[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<d[i]<<' ';
	}
	return 0;
} 
