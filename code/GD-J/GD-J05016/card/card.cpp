#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],b[N],c[N],d[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i1=1;i1<=n;i1++){
		for(int i=i1;i<=n;i++){
			if(c[a[i]]==0){
				b[i]=a[i];
				c[a[i]]++;
			}else{
				int j=i-1;
				while(b[j]!=a[i]){
					c[b[j]]=0;
					b[j]=0;
					j--;
				}
			}
		} 
		for(int i=1;i<=n;i++){
			d[b[i]]++;
			c[i]=0;
			b[i]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	return 0;
}
