#include<bits/stdc++.h>
using namespace std;
long long m[300000],a[300000];
	char b[300000],g[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
long long cnt=0,z=0;
	int nn=1,x=1;
			int jc=0;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		cin>>g[i];
		z=z+m[i];
	}
		for(int i=1;i<=z;i++){
			if(m[nn]<=x){
				a[nn+jc]=m[nn];
				b[nn+jc]=g[nn];
				x=0;
				nn++;
			}
			else x++;
		if(i==z/2&&m[nn]!=m[nn+1]){
			a[nn]=x;
			b[nn]=g[nn];
			jc=1;
			a[nn+jc]=m[nn]-x;
			b[nn+jc]=g[nn];
			nn++;
	}
	}
if(a[nn+jc]==0){
		a[nn+jc]=x;
	b[nn+jc]=g[nn];	
}
	n++;
	
int g=0;
if(z%2==1) g=1;
			int ac=n/2,bc=n/2+1;
		for(int i=0;;i=i){
		if(ac==0) break;
		if(ac==1&&g==1&&cnt!=0) break;
			if(b[ac]!=b[bc]){
				if(a[ac]>=a[bc]){
				cnt+=a[bc];
					a[ac]-=a[bc];
				a[bc]=0;
				bc++;
				if(a[ac]<=0) ac--;
			continue;
				}
				else{
				cnt+=a[ac];
				a[bc]-=a[ac];
				a[ac]=0;
				ac--;
				if(a[bc]==0) bc++;
				}
			}
			else{	
				if(a[ac]>=a[bc]){
				a[ac]-=a[bc];
				a[bc]=0;
				bc++;
				if(a[ac]==0) ac--;
			continue;
				}
				else{
				a[bc]-=a[ac];
				a[ac]=0;
				ac--;
				if(a[bc]<=0) bc++;
			
				}
		}
		
	}
	cout<<cnt;
}
