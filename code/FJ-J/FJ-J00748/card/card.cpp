#include<bits/stdc++.h>
using namespace std;
int a[5005],d[3005],j;
bool b[3005],c[3005];
int n,m,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int l=n;l>i-1;l--){	
			if(b[a[l]]==true){
				j=l;
				c[j]=true;
				j++;
				while(a[j]!=a[l]){
					if(c[j]==false) c[j]=true;
					if(b[j]==true) b[a[j]]=false;
					j++;
				}
				
			}
			if(b[a[l]]==false) b[a[l]]=true;
		}
		for(int l=n;l>i-1;l--){
			if(c[l]==false) d[a[l]]++;
			c[l]=false;
			b[a[l]]=false;
		}
	}for(int l=1;l<=m;l++){
		cout<<d[l]<<' ';
	}
	return 0;
}

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
