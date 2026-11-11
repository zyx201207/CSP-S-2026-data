#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int a[N];
int b[N];
int c[N];
int d[M];
int x,t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool f=1;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			b[a[j]]++;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]>1){
				b[a[j]]--;
				for(int k=j+1;k<=n;k++){
					if(a[k]==a[j]){
						t=k;
						break;
					} 
				}
				for(int k=j;k<=t-1;k++){
					c[k]=0;
				}
//				int k=j+1;
//				while(a[k]!=a[j]){
//					c[k]=0;
//					k++;
//				}
				j=t;
			}
			c[j]=a[j];
		}
//		for(int j=i;j<=n;j++){
//			cout<<c[j]<<' ';
//		}
//   	cout<<endl;
		for(int j=i;j<=n;j++){
			d[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
} 



