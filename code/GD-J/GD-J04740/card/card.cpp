#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],d[500005],z=1;
//a是存储数据，不变。b是记录这个编号在场上的位置。c是场上情况。z为末尾位置。 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				for(int k=b[a[i]];k<=z;k++){
					c[k]=0;
				}
			}z=b[a[j]]+1;
			c[z]+=a[j];
			b[a[j]]=z;
		}for(int j=1;j<=z;j++){
			d[c[j]]++;
			c[j]=0;
		}z=0;
	}for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	} 
} 
