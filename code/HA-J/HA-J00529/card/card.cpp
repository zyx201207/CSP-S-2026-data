#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN],d[MAXN],cnt=0;
void sss(int e,int f){
	for(int i=0;i<e;i++){
		cin>>a[i];
	}
	int b[10000]={};
	b[0]=a[0];
	int c=0,k=0;
	for(int t=1;t<=e;t++){
		while(c==t){
			if(b[k]!=a[c]){
				b[k]=a[c];
				k++;
				c++;
			}else{
				for(int j=0;j<c-1;j++){
					b[j]=0;
				}
				k=0;
				b[k]=a[c];
				k++;
				c++;
			}
		}
		for(int i=0;i<k;k++){
			int a=b[i];
			d[a++];
			cnt++;
		}
		for(int i=0;i<k;i++){
			b[i]=0;
		}
		k=0;
		c=0;
	}
	for(int i=0;i<cnt;i++){
		cout<<d[i];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=0;cin>>n>>m;
	sss(n,m);
	return 0;
}
