#include<bits/stdc++.h>
using namespace std;
int n,m,a[200006],b[200006];
int dg(int cs){
	int x=0;
	if(cs>2){
		int x1=dg(cs-1),i1;
		for(int i=0;i<n;i++){
			if(b[i]!=0&&i==0){
				x=max(a[i]&x1,x);
				i1=0;
			}else{
				x=max(a[i]&x,x);
				i1=i;
			}
		}b[i1]==1;
		return x;
	}else{
		int i1,j1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					if(a[i]&a[j]>x){
						i1=i,j1=j;
					}
					x=max(a[i]&a[j],x);
				}
			}
		}b[i1]=1,b[j1]=1;
		return x;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int z=0;
		for(int i=0;i<n;i++){
			z=max(z,a[i]);
		}cout<<z;
		return 0;
	}else if(m==n){
		int z=a[0]&a[1];
		for(int i=2;i<n;i++){
			z=z&a[i];
		}cout<<z;
		return 0;
	}cout<<dg(m);
}
