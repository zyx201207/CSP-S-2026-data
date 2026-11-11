#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n,m,a[N],x,b[N],c[N],e[N];

int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x=i-1;
//		cout<<"µÚ"<<i<<"¾Ö"<<'\n'; 
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0&&b[a[j]]<=x){
				x=b[a[j]];
			}
			else{
				b[a[j]]=j;
				c[++x]=a[j];
			}
//			for(int k=i;k<=x;k++){
//				cout<<c[k]<<' ';
//			} 
//			cout<<'\n';
		}
		for(int j=i;j<=x;j++){
			e[c[j]]++;
		}
		for(int j=1;j<=m;j++){
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<e[i]<<' ';
	}
	return 0;
} 
