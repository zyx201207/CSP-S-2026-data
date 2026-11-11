#include<bits/stdc++.h>
using namespace std;
int a[99999];
int b[99999];
int c[99999];
int d[99999];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//ios::sync_with_stdio(false);
	//4 2 1 2 1 3cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		memset(c,0,sizeof(c));
		int l=0;
		for(int j=i;j<n;j++){
			if(c[j]!=0){
				l=c[j];
			}
			c[j]=l;
			b[l++]=a[j];
		}
		for(int j=0;j<l;j++){
			for(int k=1;k<m;k++){
				if(b[j]==k)d[k]++;
			}
		}
	}for(int i=1;i<=m;i++)cout<<d[i];
	
	return 0;
}
//4 2 1 2 1 3

