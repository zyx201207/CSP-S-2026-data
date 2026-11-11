#include<bits/stdc++.h>
using namespace std;
int n,m,a[512345],b[512345],t[312345];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int l=0;
		for(int j=i;j<=n;j++){
			int o=0;
			for(int k=1;k<=l;k++){
				if(b[k]==a[j]){
					o=k;
					break;
				}
			}
			if(o==0) b[++l]=a[j];
			else{
				l=o;
				b[l]=a[j];
			}
		}
		for(int j=1;j<=l;j++){
			t[b[j]]++;
		} 
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
} 
