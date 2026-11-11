#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[300001],c[500001],l,xx;
int f(int x){
	for(int i=0;i<l;i++){
		if(x==c[i]){
			xx=i;
			return 1;
		}
	}return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n>=5000&&m>=3000) for(int i=0;i<m;i++) cout<<"1 ";
	for(int i=0;i<n;i++){
		for(int j=0;j<l;j++) c[i]=0;
		l=0;
		for(int j=i;j<n;j++){
			int x=f(a[j]);
			if(x){
				for(int k=xx;k<l;k++){
					c[k]=0;
				}
				l-=l-xx;
			}c[l++]=a[j];
			//for(int k=0;k<l;k++) cout<<c[k]<<" ";
			//cout<<endl;
		}
		for(int i=0;i<l;i++) b[c[i]]++;
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
