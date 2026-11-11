#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],num,b[300008],c[300008];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		num=0;
		for(int j=i;j<n;j++){
			for(int k=num-1;k>=0;k--){
				if(b[k]==a[j]){
					num=k;
					break;
				}
			}
			b[num]=a[j];
			num++;
		}
		for(int j=0;j<num;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
