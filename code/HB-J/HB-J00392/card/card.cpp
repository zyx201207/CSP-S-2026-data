#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int b[300000];
int a[500000];
int c[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		int idx=0;
		for(int j=i;j<=n;j++){
			idx++;
			bool f=0;
			int iidx=idx;
			for(int s=1;s<iidx;s++){
				if(a[j]==c[s]&&!f) f=1;
				if(f){
					c[s]=0;
					idx--;
				}
			}c[idx]=a[j];
		}
	}for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
