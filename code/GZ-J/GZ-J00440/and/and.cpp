//GZ-J00440 遵义市第四中学 杨宜炜
#include<bits/stdc++.h>
using namespace std;
int b,n,m,a[200020],d;
int main(){
	freopen("and.in"."r",stdin);
	freopen("and.out"."w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==m){
		int k=a[0];
		for(int i=0;i<n;i++){
			k=(k&a[i]);
		}
		cout<<k;
		return 0;
	}
	if(n-1==m){
		int k=a[0];
		d=a[1];
		for(int i=1;i<n;i++){
			d=(d&a[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j!=i){
					k=(k&a[i]);
				}
			}
			d=max(d,k);
		}
		cout<<d;
		return 0;
	}
	if(m==1){
		for(int i=0;i<n;i++){
			d=max(d,a[i]);
		}
		cout<<d;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				d=max(a[i]&a[j],d);
			}
		}
		cout<<d;
		return 0;
	}
	for(b=1;b<=(1>>n);b++){
		int l=b,r=0;
		while(l>>1){
			if(l%2){
				r++;
			}
		}
		if(r==m){
			l=b;
			while(l>>1){
				r=1+1; 
			}
		}
	}
}
