#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],d,k,f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	k=-99999999;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>f) f=a[i];
	}
	if(m==1){
		k=f;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				d=a[i]&a[j];
				if(d>k) k=d;
			}
		}
	}else if(m==n){
		d=a[1];
		for(int i=2;i<=n;i++){
			d=d&a[i];
		}
		k=d;
	}else if(m==3){
		for(int o=1;o<=n;o++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j||j==o||o==i) continue;
					d=a[o]&a[i]&a[j];
					if(d>k) k=d;
				}
			}
		}
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			d=a[1];
			for(int j=2;j<=n;j++){
				if(j==i) continue;
				d=d&a[j];
			}
			if(d>k) k=d;
		}
	}
	cout<<k;
	return 0;
}