//GZ-J00445   遵义市新浦新区滨湖中学   范曾
#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	
	for(int p=0;p<n;p++){
		for(int i=p;i<n;i++){
			for(int j=p;j<i;j++){
				if(c[i]==c[j]){
					for(int k=j+1;k<=i;k++){
						c[k]=0;
					}
				}
			}
		}
		for(int i=p;i<n;i++){
			b[c[i]]++;
		}
		for(int i=0;i<n;i++){
			c[i]=a[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

